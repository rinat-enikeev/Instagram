//
//  STXLikesCell.h
//  STXDynamicTableViewExample
//
//  Created by Jesse Armand on 10/4/14.
//  Copyright (c) 2014 2359 Media Pte Ltd. All rights reserved.
//

@import UIKit;

typedef NS_ENUM(NSUInteger, STXLikesCellStyle) {
    STXLikesCellStyleLikesCount,
    STXLikesCellStyleLikers
};

@class STXLikesCell;

@protocol STXLikesCellDelegate <NSObject>

@optional

- (void)likesCellWillShowLikes:(STXLikesCell *)likesCell;
- (void)likesCellDidSelectLiker:(NSString *)liker;

@end

@interface STXLikesCell : UITableViewCell

- (void)setLikersCount:(NSInteger)count likers:(NSOrderedSet<NSObject<InstaUser> *> *)likers;

@property (weak, nonatomic) id <STXLikesCellDelegate> delegate;

- (instancetype)initWithStyle:(STXLikesCellStyle)style likesCount:(NSInteger *)likesCount likers:(NSOrderedSet<NSObject<InstaUser> *> *)likers reuseIdentifier:(NSString *)reuseIdentifier;

@end
