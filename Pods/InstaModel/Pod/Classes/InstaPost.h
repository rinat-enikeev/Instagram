//
//  InstaPost.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#ifndef InstaPost_h
#define InstaPost_h

@import Foundation;

@protocol InstaUser;
@protocol InstaImage;
@protocol InstaTag;
@protocol InstaVideo;
@protocol InstaAttribution;
@protocol InstaUserOnPost;
@protocol InstaCaption;
@protocol InstaLocation;
@protocol InstaComment;

@protocol InstaPost <NSObject>

@property (nullable, nonatomic, retain, readonly) NSString *identifier;
@property (nullable, nonatomic, retain, readonly) NSNumber *commentsCount;
@property (nullable, nonatomic, retain, readonly) NSDate   *created;
@property (nullable, nonatomic, retain, readonly) NSString *filter;
@property (nullable, nonatomic, retain, readonly) NSNumber *likesCount;
@property (nullable, nonatomic, retain, readonly) NSString *link;
@property (nullable, nonatomic, retain, readonly) NSString *type;
@property (nullable, nonatomic, retain, readonly) NSNumber *userHasLiked;
@property (nullable, nonatomic, retain, readonly) NSNumber *distance;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaLocation> *location;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaUser>    *author;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaCaption> *caption;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaImage>   *imageLow;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaImage>   *imageStd;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaImage>   *imageThumb;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaVideo> *videoLowBand;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaVideo> *videoLowRes;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaVideo> *videoStdRes;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaAttribution> *attribution;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaUser> *> *likers;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaTag> *>  *tags;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaUserOnPost> *> *usersOnPost;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaComment> *> *comments;

@end


#endif /* InstaPost_h */
