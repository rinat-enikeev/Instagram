//
//  STXUserItem.h
//  STXDynamicTableViewExample
//
//  Created by Jesse Armand on 3/4/14.
//  Copyright (c) 2014 2359 Media Pte Ltd. All rights reserved.
//

@import Foundation;

@protocol STXUserItem <NSObject>

@property (nonatomic, strong) UIImage *profilePicture;

- (NSURL *)profilePictureURL;

- (NSString *)userID;
- (NSString *)username;
- (NSString *)fullname;

@end
