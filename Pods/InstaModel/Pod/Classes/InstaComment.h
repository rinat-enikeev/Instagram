//
//  InstaComment.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#ifndef InstaComment_h
#define InstaComment_h

@import Foundation;

@protocol InstaUser;
@protocol InstaPost;

@protocol InstaComment <NSObject>

@property (nullable, nonatomic, retain, readonly) NSDate *created;
@property (nullable, nonatomic, retain, readonly) NSString *identifier;
@property (nullable, nonatomic, retain, readonly) NSString *text;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaUser> *from;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaPost> *post;

@end

#endif /* InstaComment_h */
