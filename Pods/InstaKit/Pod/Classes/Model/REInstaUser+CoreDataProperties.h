//
//  REInstaUser+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaUser (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *bio;
@property (nullable, nonatomic, retain) NSString *firstName;
@property (nullable, nonatomic, retain) NSNumber *followedByCount;
@property (nullable, nonatomic, retain) NSNumber *followsCount;
@property (nullable, nonatomic, retain) NSString *fullName;
@property (nullable, nonatomic, retain) NSString *identifier;
@property (nullable, nonatomic, retain) NSString *lastName;
@property (nullable, nonatomic, retain) NSNumber *mediaCount;
@property (nullable, nonatomic, retain) NSString *profilePictureLocalPath;
@property (nullable, nonatomic, retain) NSString *profilePictureUrl;
@property (nullable, nonatomic, retain) NSString *username;
@property (nullable, nonatomic, retain) NSString *website;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaCaption *> *captions;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaComment *> *comments;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaPost *> *likes;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaUserOnPost *> *onPostPhotos;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaPost *> *posts;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaRelationship *> *relationshipRequests;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaRelationship *> *relationships;

@end

@interface REInstaUser (CoreDataGeneratedAccessors)

- (void)insertObject:(REInstaCaption *)value inCaptionsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromCaptionsAtIndex:(NSUInteger)idx;
- (void)insertCaptions:(NSArray<REInstaCaption *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeCaptionsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInCaptionsAtIndex:(NSUInteger)idx withObject:(REInstaCaption *)value;
- (void)replaceCaptionsAtIndexes:(NSIndexSet *)indexes withCaptions:(NSArray<REInstaCaption *> *)values;
- (void)addCaptionsObject:(REInstaCaption *)value;
- (void)removeCaptionsObject:(REInstaCaption *)value;
- (void)addCaptions:(NSOrderedSet<REInstaCaption *> *)values;
- (void)removeCaptions:(NSOrderedSet<REInstaCaption *> *)values;

- (void)insertObject:(REInstaComment *)value inCommentsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromCommentsAtIndex:(NSUInteger)idx;
- (void)insertComments:(NSArray<REInstaComment *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeCommentsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInCommentsAtIndex:(NSUInteger)idx withObject:(REInstaComment *)value;
- (void)replaceCommentsAtIndexes:(NSIndexSet *)indexes withComments:(NSArray<REInstaComment *> *)values;
- (void)addCommentsObject:(REInstaComment *)value;
- (void)removeCommentsObject:(REInstaComment *)value;
- (void)addComments:(NSOrderedSet<REInstaComment *> *)values;
- (void)removeComments:(NSOrderedSet<REInstaComment *> *)values;

- (void)insertObject:(REInstaPost *)value inLikesAtIndex:(NSUInteger)idx;
- (void)removeObjectFromLikesAtIndex:(NSUInteger)idx;
- (void)insertLikes:(NSArray<REInstaPost *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeLikesAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInLikesAtIndex:(NSUInteger)idx withObject:(REInstaPost *)value;
- (void)replaceLikesAtIndexes:(NSIndexSet *)indexes withLikes:(NSArray<REInstaPost *> *)values;
- (void)addLikesObject:(REInstaPost *)value;
- (void)removeLikesObject:(REInstaPost *)value;
- (void)addLikes:(NSOrderedSet<REInstaPost *> *)values;
- (void)removeLikes:(NSOrderedSet<REInstaPost *> *)values;

- (void)insertObject:(REInstaUserOnPost *)value inOnPostPhotosAtIndex:(NSUInteger)idx;
- (void)removeObjectFromOnPostPhotosAtIndex:(NSUInteger)idx;
- (void)insertOnPostPhotos:(NSArray<REInstaUserOnPost *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeOnPostPhotosAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInOnPostPhotosAtIndex:(NSUInteger)idx withObject:(REInstaUserOnPost *)value;
- (void)replaceOnPostPhotosAtIndexes:(NSIndexSet *)indexes withOnPostPhotos:(NSArray<REInstaUserOnPost *> *)values;
- (void)addOnPostPhotosObject:(REInstaUserOnPost *)value;
- (void)removeOnPostPhotosObject:(REInstaUserOnPost *)value;
- (void)addOnPostPhotos:(NSOrderedSet<REInstaUserOnPost *> *)values;
- (void)removeOnPostPhotos:(NSOrderedSet<REInstaUserOnPost *> *)values;

- (void)insertObject:(REInstaPost *)value inPostsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromPostsAtIndex:(NSUInteger)idx;
- (void)insertPosts:(NSArray<REInstaPost *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removePostsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInPostsAtIndex:(NSUInteger)idx withObject:(REInstaPost *)value;
- (void)replacePostsAtIndexes:(NSIndexSet *)indexes withPosts:(NSArray<REInstaPost *> *)values;
- (void)addPostsObject:(REInstaPost *)value;
- (void)removePostsObject:(REInstaPost *)value;
- (void)addPosts:(NSOrderedSet<REInstaPost *> *)values;
- (void)removePosts:(NSOrderedSet<REInstaPost *> *)values;

- (void)insertObject:(REInstaRelationship *)value inRelationshipRequestsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromRelationshipRequestsAtIndex:(NSUInteger)idx;
- (void)insertRelationshipRequests:(NSArray<REInstaRelationship *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeRelationshipRequestsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInRelationshipRequestsAtIndex:(NSUInteger)idx withObject:(REInstaRelationship *)value;
- (void)replaceRelationshipRequestsAtIndexes:(NSIndexSet *)indexes withRelationshipRequests:(NSArray<REInstaRelationship *> *)values;
- (void)addRelationshipRequestsObject:(REInstaRelationship *)value;
- (void)removeRelationshipRequestsObject:(REInstaRelationship *)value;
- (void)addRelationshipRequests:(NSOrderedSet<REInstaRelationship *> *)values;
- (void)removeRelationshipRequests:(NSOrderedSet<REInstaRelationship *> *)values;

- (void)insertObject:(REInstaRelationship *)value inRelationshipsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromRelationshipsAtIndex:(NSUInteger)idx;
- (void)insertRelationships:(NSArray<REInstaRelationship *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeRelationshipsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInRelationshipsAtIndex:(NSUInteger)idx withObject:(REInstaRelationship *)value;
- (void)replaceRelationshipsAtIndexes:(NSIndexSet *)indexes withRelationships:(NSArray<REInstaRelationship *> *)values;
- (void)addRelationshipsObject:(REInstaRelationship *)value;
- (void)removeRelationshipsObject:(REInstaRelationship *)value;
- (void)addRelationships:(NSOrderedSet<REInstaRelationship *> *)values;
- (void)removeRelationships:(NSOrderedSet<REInstaRelationship *> *)values;

@end

NS_ASSUME_NONNULL_END
