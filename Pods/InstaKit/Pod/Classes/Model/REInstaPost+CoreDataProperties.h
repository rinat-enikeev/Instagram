//
//  REInstaPost+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaPost.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaPost (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *commentsCount;
@property (nullable, nonatomic, retain) NSNumber *createdTimestamp;
@property (nullable, nonatomic, retain) NSNumber *distance;
@property (nullable, nonatomic, retain) NSString *filter;
@property (nullable, nonatomic, retain) NSString *identifier;
@property (nullable, nonatomic, retain) NSNumber *likesCount;
@property (nullable, nonatomic, retain) NSString *link;
@property (nullable, nonatomic, retain) NSString *type;
@property (nullable, nonatomic, retain) NSNumber *userHasLiked;
@property (nullable, nonatomic, retain) REInstaAttribution *attribution;
@property (nullable, nonatomic, retain) REInstaUser *author;
@property (nullable, nonatomic, retain) REInstaCaption *caption;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaComment *> *comments;
@property (nullable, nonatomic, retain) REInstaImage *imageLow;
@property (nullable, nonatomic, retain) REInstaImage *imageStd;
@property (nullable, nonatomic, retain) REInstaImage *imageThumb;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaUser *> *likers;
@property (nullable, nonatomic, retain) REInstaLocation *location;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaTag *> *tags;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaUserOnPost *> *usersOnPost;
@property (nullable, nonatomic, retain) REInstaVideo *videoLowBand;
@property (nullable, nonatomic, retain) REInstaVideo *videoLowRes;
@property (nullable, nonatomic, retain) REInstaVideo *videoStdRes;

@end

@interface REInstaPost (CoreDataGeneratedAccessors)

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

- (void)insertObject:(REInstaUser *)value inLikersAtIndex:(NSUInteger)idx;
- (void)removeObjectFromLikersAtIndex:(NSUInteger)idx;
- (void)insertLikers:(NSArray<REInstaUser *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeLikersAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInLikersAtIndex:(NSUInteger)idx withObject:(REInstaUser *)value;
- (void)replaceLikersAtIndexes:(NSIndexSet *)indexes withLikers:(NSArray<REInstaUser *> *)values;
- (void)addLikersObject:(REInstaUser *)value;
- (void)removeLikersObject:(REInstaUser *)value;
- (void)addLikers:(NSOrderedSet<REInstaUser *> *)values;
- (void)removeLikers:(NSOrderedSet<REInstaUser *> *)values;

- (void)insertObject:(REInstaTag *)value inTagsAtIndex:(NSUInteger)idx;
- (void)removeObjectFromTagsAtIndex:(NSUInteger)idx;
- (void)insertTags:(NSArray<REInstaTag *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeTagsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInTagsAtIndex:(NSUInteger)idx withObject:(REInstaTag *)value;
- (void)replaceTagsAtIndexes:(NSIndexSet *)indexes withTags:(NSArray<REInstaTag *> *)values;
- (void)addTagsObject:(REInstaTag *)value;
- (void)removeTagsObject:(REInstaTag *)value;
- (void)addTags:(NSOrderedSet<REInstaTag *> *)values;
- (void)removeTags:(NSOrderedSet<REInstaTag *> *)values;

- (void)insertObject:(REInstaUserOnPost *)value inUsersOnPostAtIndex:(NSUInteger)idx;
- (void)removeObjectFromUsersOnPostAtIndex:(NSUInteger)idx;
- (void)insertUsersOnPost:(NSArray<REInstaUserOnPost *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removeUsersOnPostAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInUsersOnPostAtIndex:(NSUInteger)idx withObject:(REInstaUserOnPost *)value;
- (void)replaceUsersOnPostAtIndexes:(NSIndexSet *)indexes withUsersOnPost:(NSArray<REInstaUserOnPost *> *)values;
- (void)addUsersOnPostObject:(REInstaUserOnPost *)value;
- (void)removeUsersOnPostObject:(REInstaUserOnPost *)value;
- (void)addUsersOnPost:(NSOrderedSet<REInstaUserOnPost *> *)values;
- (void)removeUsersOnPost:(NSOrderedSet<REInstaUserOnPost *> *)values;

@end

NS_ASSUME_NONNULL_END
