//
//  InstaUserOnPost.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#ifndef InstaUserOnPost_h
#define InstaUserOnPost_h


@import Foundation;

@protocol InstaUser;
@protocol InstaPost;

@protocol InstaUserOnPost <NSObject>

@property (nullable, nonatomic, retain, readonly) NSNumber *x;
@property (nullable, nonatomic, retain, readonly) NSNumber *y;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaPost> *post;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaUser> *user;

@end


#endif /* InstaUserOnPost_h */
