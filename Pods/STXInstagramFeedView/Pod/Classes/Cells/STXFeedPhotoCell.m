//
//  STXFeedPhotoCell.m
//  STXDynamicTableView
//
//  Created by Triệu Khang on 24/3/14.
//  Copyright (c) 2014 2359 Media. All rights reserved.
//

#import "STXFeedPhotoCell.h"

@interface STXFeedPhotoCell ()

@property (weak, nonatomic) IBOutlet UILabel *profileLabel;
@property (weak, nonatomic) IBOutlet UILabel *dateLabel;

@end

@implementation STXFeedPhotoCell

- (void)awakeFromNib
{
    [super awakeFromNib];

    self.profileImageView.userInteractionEnabled = YES;
    
    UITapGestureRecognizer *imageGestureRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(profileTapped:)];
    [self.profileImageView addGestureRecognizer:imageGestureRecognizer];
    
    self.profileLabel.userInteractionEnabled = YES;
    
    UITapGestureRecognizer *labelGestureRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(profileTapped:)];
    [self.profileLabel addGestureRecognizer:labelGestureRecognizer];
    
    self.dateLabel.backgroundColor = [self.dateLabel superview].backgroundColor;
    
    self.profileImageView.clipsToBounds = YES;

    self.postImageView.clipsToBounds = YES;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];
}

-(void)prepareForReuse
{
    self.profileImageView.image = nil;
    self.postImageView.image = nil;
}

- (void)setPostItem:(NSObject<InstaPost> *)postItem
{
    if (_postItem != postItem) {
        _postItem = postItem;
        
        self.dateLabel.textColor = [UIColor grayColor];
        self.dateLabel.text = [MHPrettyDate prettyDateFromDate:postItem.created withFormat:MHPrettyDateLongRelativeTime];
        
        NSObject<InstaUser> *userItem = postItem.author;
        NSString *name = userItem.fullName;
        self.profileLabel.text = name;
    }
}

#pragma mark - Actions

- (void)profileTapped:(UIGestureRecognizer *)recognizer
{
    if ([self.delegate respondsToSelector:@selector(feedCellWillShowPoster:)])
        [self.delegate feedCellWillShowPoster:self.postItem.author];
}

@end
