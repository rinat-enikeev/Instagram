//
//  STXPostItem.h
//  STXDynamicTableViewExample
//
//  Created by Jesse Armand on 3/4/14.
//  Copyright (c) 2014 2359 Media Pte Ltd. All rights reserved.
//

@import Foundation;
@import UIKit;

@protocol STXUserItem;

@protocol STXPostItem <NSObject>

@property (nonatomic, strong) UIImage *standardImage;
@property (nonatomic, strong) UIImage *thumbImage;
@property (nonatomic, strong) UIImage *lowImage;

- (NSURL *)standardImageURL;
- (NSURL *)thumbImageURL;
- (NSURL *)lowImageURL;

- (NSString *)postID;
- (NSDate *)postDate;
- (NSURL *)sharedURL;
- (NSString *)captionText;
- (NSDictionary *)caption;
- (NSDictionary *)likes;
- (NSArray *)comments;

- (BOOL)liked;

- (NSInteger)totalLikes;
- (NSInteger)totalComments;

- (id<STXUserItem>)user;

@end
