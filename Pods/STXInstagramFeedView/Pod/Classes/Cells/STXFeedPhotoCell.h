//
//  STXFeedPhotoCell.h
//  STXDynamicTableView
//
//  Created by Triệu Khang on 24/3/14.
//  Copyright (c) 2014 2359 Media. All rights reserved.
//

@import UIKit;

@class STXFeedPhotoCell;
@protocol InstaUser;
@protocol InstaPost;

@protocol STXFeedPhotoCellDelegate <NSObject>

@optional

- (void)feedCellWillBeDisplayed:(STXFeedPhotoCell*)cell; // use to load images
- (void)feedCellWillShowPoster:(NSObject<InstaUser>*)poster;

@end

@interface STXFeedPhotoCell : UITableViewCell

@property (strong, nonatomic) NSIndexPath *indexPath;

@property (weak, nonatomic) IBOutlet UIImageView *profileImageView;
@property (weak, nonatomic) IBOutlet UIImageView *postImageView;

@property (strong, nonatomic) NSObject <InstaPost>* postItem;

@property (weak, nonatomic) id <STXFeedPhotoCellDelegate> delegate;

@end
