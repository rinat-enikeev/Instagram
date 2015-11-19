//
//  ViewController.m
//  Instagram
//
//  Created by Rinat Enikeev on 19/11/15.
//  Copyright © 2015 Rinat Enikeev. All rights reserved.
//

#import "REInstaPopularFeedViewController.h"
#import <InstaKit/InstaKit.h>
#import <STXInstagramFeedView/STXDynamicTableView.h>
#import <InstaModel/InstaModel.h>
#import <Reachability/Reachability.h>
#import "UIViewController+InformUser.h"

@interface REInstaPopularFeedViewController () <STXFeedPhotoCellDelegate, STXLikesCellDelegate, STXCaptionCellDelegate, STXCommentCellDelegate, STXUserActionDelegate>

// views
@property (strong, nonatomic) UIActivityIndicatorView *activityIndicatorView;

// services
@property (strong, nonatomic) InstaKit* instaKit;
@property (strong, nonatomic) Reachability* internetReachability;

// instagram-like feed support
@property (strong, nonatomic) STXFeedTableViewDataSource *tableViewDataSource;
@property (strong, nonatomic) STXFeedTableViewDelegate *tableViewDelegate;

// configuration
@property (strong, nonatomic) NSNumber* fetchedPostsLimit;


@end

@implementation REInstaPopularFeedViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 1. Delegate UITableView datasource and delegate to STX.
    STXFeedTableViewDataSource *dataSource = [[STXFeedTableViewDataSource alloc] initWithController:self tableView:self.tableView];
    self.tableView.dataSource = dataSource;
    self.tableViewDataSource = dataSource;
    
    STXFeedTableViewDelegate *delegate = [[STXFeedTableViewDelegate alloc] initWithController:self];
    self.tableView.delegate = delegate;
    self.tableViewDelegate = delegate;
    
    // 2. Full screen activity indicator
    self.activityIndicatorView = [self activityIndicatorViewOnView:self.view];
    
    // 3. Refresh Control
    self.refreshControl = [[UIRefreshControl alloc] init];
    [self.refreshControl addTarget:self action:@selector(renewFeed) forControlEvents:UIControlEventValueChanged];
    
    // 4. Internet reachability. Used to download images for visible cells
    //     right after internet connection became alive.
    self.internetReachability = [Reachability reachabilityForInternetConnection];
    
    __weak REInstaPopularFeedViewController* weakSelf = self;
    _internetReachability.unreachableBlock = ^(Reachability*reach)
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            [weakSelf informUserThatInternetIsOffline];
        });
    };
    
    _internetReachability.reachableBlock = ^(Reachability*reach)
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            for (UITableViewCell* cell in weakSelf.tableView.visibleCells) {
                if ([cell isKindOfClass:[STXFeedPhotoCell class]]) {
                    // download images for visible cells if they are not yet downloaded
                    [weakSelf feedCellWillBeDisplayed:(STXFeedPhotoCell*)cell];
                }
            }
        });
    };
    
    [_internetReachability startNotifier];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    // fetch posts if not presented.
    // if there are no posts in db, renew from Instagram.
    if ([self.tableViewDataSource.posts count] == 0) {
        [self.activityIndicatorView startAnimating];
        NSUInteger fetchedPostsCount = [self fetchFeed:[_fetchedPostsLimit integerValue]];
        
        if (fetchedPostsCount < 1) {
            [self.activityIndicatorView startAnimating];
            [self updateFeed];
        }
    }
    
    [self becomeUserInformSourceViewController];
    
    if (![_internetReachability isReachable]) {
        [self informUserThatInternetIsOffline];
    }
}

- (void)dealloc
{
    // To prevent crash when popping this from navigation controller
    self.tableView.delegate = nil;
    self.tableView.dataSource = nil;
}

/**
 *  @brief  Updates feed based on internet reachability and inform user appropriately.
 */
-(void)updateFeed {
    
    if ([_internetReachability isReachable]) {
        [self renewFeed];
    } else {
        [self fetchFeed:self.fetchedPostsLimit.integerValue];
    }
}

/**
 *  @brief  Fetches posts from persistence.
 *
 *  @param limit maximum number of posts to fetch.
 *
 *  @return number of posts fetched.
 */
-(NSUInteger)fetchFeed:(NSUInteger)limit {
    
    NSArray<NSSortDescriptor *>* sds = @[[[NSSortDescriptor alloc] initWithKey:@"likesCount" ascending:false]];
    
    NSError* error = nil;
    NSArray* posts = [[_instaKit postService] fetchPostsWithPredicate:nil sortDescriptors:sds limit:limit error:&error];
    
    if (error != nil) {
        [self informUserWithErrorMessage:error.localizedDescription withTitle:nil];
    } else {
        self.tableViewDataSource.posts = [posts copy];
        [self.tableView reloadData];
    }
    
    [self.activityIndicatorView stopAnimating];
    [self.refreshControl endRefreshing];
    
    return [posts count];
}

/**
 *  @brief  Downloads last popular posts from Instagram.
 */
- (void)renewFeed
{
    [[_instaKit postService] renewMediaPopularWithProgress:nil success:^(NSArray *objects) {
        self.tableViewDataSource.posts = [objects copy];
        [self.tableView reloadData];
        [self.activityIndicatorView stopAnimating];
        [self.refreshControl endRefreshing];
    } failure:^(NSError *error) {
        [self.activityIndicatorView stopAnimating];
        [self.refreshControl endRefreshing];
        [self informUserWithErrorMessage:error.localizedDescription withTitle:nil];
    }];
}


#pragma mark - STXFeedPhotoCellDelegate
- (void)feedCellWillBeDisplayed:(STXFeedPhotoCell *)cell
{
    
    NSObject<InstaImage>* imgStd = cell.postItem.imageStd;
    if (imgStd.localPath == nil) {
        
        if ([_internetReachability isReachable]) {
            [[_instaKit blobService] renewImageBlobFor:imgStd withProgress:nil success:^(NSObject<InstaImage> *image) {
                [self updateStdImageInPost:cell];
            } failure:^(NSError *error) {
                [self informUserWithErrorMessage:error.localizedDescription withTitle:nil];
            }];
        } else {
            cell.postImageView.image = [UIImage imageNamed:@"InstagramPhotoPostPlaceholderImage"];
        }
    } else {
        [self updateStdImageInPost:cell];
    }
    
    NSObject<InstaUser>* author = cell.postItem.author;
    if (author.profilePictureLocalPath == nil) {
        if ([_internetReachability isReachable]) {
            [[_instaKit blobService] renewProfileImageBlobFor:author withProgress:nil success:^(NSObject<InstaUser> *user) {
                [self updateProfilePictureIn:cell];
            } failure:^(NSError *error) {
                [self informUserWithErrorMessage:error.localizedDescription withTitle:nil];
            }];
        } else {
            [cell.profileImageView setCircledImageFrom:[UIImage imageNamed:@"InstagramPhotoPostPlaceholderImage"] placeholderImage:[UIImage imageNamed:@"InstagramPhotoPostPlaceholderImage"] borderWidth:2];
        }
        
    } else {
        [self updateProfilePictureIn:cell];
    }
}

/**
 *  @brief  Assume thatcell.postItem.imageStd.localPath is not null.
 */
-(void)updateStdImageInPost:(STXFeedPhotoCell *)cell {
    NSObject<InstaImage>* imgStd = cell.postItem.imageStd;
    dispatch_async(dispatch_get_global_queue( DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        UIImage* postStdImage = [UIImage imageWithContentsOfFile:[self documentsPathForFileName:imgStd.localPath]];
        dispatch_async(dispatch_get_main_queue(), ^(void){
            cell.postImageView.image = postStdImage;
        });
    });
}

/**
 *  @brief  Assume that cell.postItem.author.profilePictureLocalPath is not null.
 */
-(void)updateProfilePictureIn:(STXFeedPhotoCell *)cell {
    NSObject<InstaUser>* author = cell.postItem.author;
    dispatch_async(dispatch_get_global_queue( DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        UIImage* authorImage = [UIImage imageWithContentsOfFile:[self documentsPathForFileName:author.profilePictureLocalPath]];
        dispatch_async(dispatch_get_main_queue(), ^(void){
            [cell.profileImageView setCircledImageFrom:authorImage placeholderImage:[UIImage imageNamed:@"InstagramPhotoPostPlaceholderImage"] borderWidth:2];
        });
    });
}

#pragma mark - private Helpers
- (NSString *)documentsPathForFileName:(NSString *)name
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES);
    NSString *documentsPath = [paths objectAtIndex:0];
    
    return [documentsPath stringByAppendingPathComponent:name];
}

-(void)informUserThatInternetIsOffline {
    [self informUserWithWarnMessage:NSLocalizedString(@"The Internet connection appears to be offline.", @"The Internet connection appears to be offline.") withTitle:nil];
}

@end
