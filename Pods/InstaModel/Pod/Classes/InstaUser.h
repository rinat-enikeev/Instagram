//
//  InstaUser.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#ifndef InstaUser_h
#define InstaUser_h

@import Foundation;

@protocol InstaCaption;
@protocol InstaComment;
@protocol InstaPost;
@protocol InstaVideo;
@protocol InstaRelationship;
@protocol InstaUserOnPost;

@protocol InstaUser <NSObject>

@property (nullable, nonatomic, retain, readonly) NSString *identifier;
@property (nullable, nonatomic, retain, readonly) NSString *username;
@property (nullable, nonatomic, retain, readonly) NSString *fullName;
@property (nullable, nonatomic, retain, readonly) NSString *bio;
@property (nullable, nonatomic, retain, readonly) NSString *profilePictureUrl;
@property (nullable, nonatomic, retain, readonly) NSString *profilePictureLocalPath;
@property (nullable, nonatomic, retain, readonly) NSString *website;
@property (nullable, nonatomic, retain, readonly) NSNumber *followsCount;
@property (nullable, nonatomic, retain, readonly) NSNumber *followedByCount;
@property (nullable, nonatomic, retain, readonly) NSNumber *mediaCount;
@property (nullable, nonatomic, retain, readonly) NSString *firstName;
@property (nullable, nonatomic, retain, readonly) NSString *lastName;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaCaption> *> *captions;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaComment> *> *comments;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaPost> *> *likes;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaPost> *> *posts;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaRelationship> *> *relationships;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaRelationship> *> *relationshipRequests;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaUserOnPost> *> *onPostPhotos;

@end


#endif /* InstaUser_h */
