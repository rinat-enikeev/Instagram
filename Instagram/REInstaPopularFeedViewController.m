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

@interface REInstaPopularFeedViewController () <STXFeedPhotoCellDelegate, STXLikesCellDelegate, STXCaptionCellDelegate, STXCommentCellDelegate, STXUserActionDelegate>

@property(nonatomic, strong) InstaKit* instaKit;

@property (strong, nonatomic) UIActivityIndicatorView *activityIndicatorView;
@property (strong, nonatomic) STXFeedTableViewDataSource *tableViewDataSource;
@property (strong, nonatomic) STXFeedTableViewDelegate *tableViewDelegate;

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
    
    // 4. Renew feed
    [self renewFeed];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    if ([self.tableViewDataSource.posts count] == 0) {
        [self.activityIndicatorView startAnimating];
    }
}

- (void)dealloc
{
    // To prevent crash when popping this from navigation controller
    self.tableView.delegate = nil;
    self.tableView.dataSource = nil;
}

/**
 *  @brief  Reloads posts from Instagram api.
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
        NSLog(@"%@", error);
    }];
    
    
}

#pragma mark - STXFeedPhotoCellDelegate
- (void)feedCellWillBeDisplayed:(STXFeedPhotoCell *)cell
{
    // 1. Load standart post image for cell
    NSObject<InstaImage>* imgStd = cell.postItem.imageStd;
    if (imgStd.localPath == nil) {
        [[_instaKit blobService] renewImageBlobFor:imgStd withProgress:nil success:^(NSObject<InstaImage> *image) {
            [self updateStdImageInPost:cell];
        } failure:^(NSError *error) {
            NSLog(@"%@", error.localizedDescription);
        }];
    } else {
        [self updateStdImageInPost:cell];
    }
    
    // 2. Load profile picture for photo cell
    NSObject<InstaUser>* author = cell.postItem.author;
    if (author.profilePictureLocalPath == nil) {
        [[_instaKit blobService] renewProfileImageBlobFor:author withProgress:nil success:^(NSObject<InstaUser> *user) {
            [self updateProfilePictureIn:cell];
        } failure:^(NSError *error) {
            NSLog(@"%@", error.localizedDescription);
        }];
        
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
        UIImage* postStdImage = [UIImage imageWithContentsOfFile:imgStd.localPath];
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
        UIImage* authorImage = [UIImage imageWithContentsOfFile:author.profilePictureLocalPath];
        dispatch_async(dispatch_get_main_queue(), ^(void){
            [cell.profileImageView setCircledImageFrom:authorImage placeholderImage:[UIImage imageNamed:@"ProfilePlaceholder"] borderWidth:2];
        });
    });
}

#pragma mark - STXUserActionDelegate

- (void)userDidLike:(STXUserActionCell *)userActionCell
{
    
}

- (void)userDidUnlike:(STXUserActionCell *)userActionCell
{
    
}

- (void)userWillComment:(STXUserActionCell *)userActionCell
{
    
}

- (void)userWillShare:(STXUserActionCell *)userActionCell
{
    
}

@end
