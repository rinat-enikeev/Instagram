//
//  REInstaAttribution+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaAttribution.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaAttribution (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *name;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaPost *> *posts;

@end

@interface REInstaAttribution (CoreDataGeneratedAccessors)

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

@end

NS_ASSUME_NONNULL_END
