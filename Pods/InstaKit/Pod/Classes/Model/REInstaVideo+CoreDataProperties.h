//
//  REInstaVideo+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaVideo.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaVideo (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *height;
@property (nullable, nonatomic, retain) NSString *localPath;
@property (nullable, nonatomic, retain) NSString *url;
@property (nullable, nonatomic, retain) NSNumber *width;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaPost *> *postLowBand;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaPost *> *postLowRes;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaPost *> *postStdRes;

@end

@interface REInstaVideo (CoreDataGeneratedAccessors)

- (void)insertObject:(REInstaPost *)value inPostLowBandAtIndex:(NSUInteger)idx;
- (void)removeObjectFromPostLowBandAtIndex:(NSUInteger)idx;
- (void)insertPostLowBand:(NSArray<REInstaPost *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removePostLowBandAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInPostLowBandAtIndex:(NSUInteger)idx withObject:(REInstaPost *)value;
- (void)replacePostLowBandAtIndexes:(NSIndexSet *)indexes withPostLowBand:(NSArray<REInstaPost *> *)values;
- (void)addPostLowBandObject:(REInstaPost *)value;
- (void)removePostLowBandObject:(REInstaPost *)value;
- (void)addPostLowBand:(NSOrderedSet<REInstaPost *> *)values;
- (void)removePostLowBand:(NSOrderedSet<REInstaPost *> *)values;

- (void)insertObject:(REInstaPost *)value inPostLowResAtIndex:(NSUInteger)idx;
- (void)removeObjectFromPostLowResAtIndex:(NSUInteger)idx;
- (void)insertPostLowRes:(NSArray<REInstaPost *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removePostLowResAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInPostLowResAtIndex:(NSUInteger)idx withObject:(REInstaPost *)value;
- (void)replacePostLowResAtIndexes:(NSIndexSet *)indexes withPostLowRes:(NSArray<REInstaPost *> *)values;
- (void)addPostLowResObject:(REInstaPost *)value;
- (void)removePostLowResObject:(REInstaPost *)value;
- (void)addPostLowRes:(NSOrderedSet<REInstaPost *> *)values;
- (void)removePostLowRes:(NSOrderedSet<REInstaPost *> *)values;

- (void)insertObject:(REInstaPost *)value inPostStdResAtIndex:(NSUInteger)idx;
- (void)removeObjectFromPostStdResAtIndex:(NSUInteger)idx;
- (void)insertPostStdRes:(NSArray<REInstaPost *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removePostStdResAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInPostStdResAtIndex:(NSUInteger)idx withObject:(REInstaPost *)value;
- (void)replacePostStdResAtIndexes:(NSIndexSet *)indexes withPostStdRes:(NSArray<REInstaPost *> *)values;
- (void)addPostStdResObject:(REInstaPost *)value;
- (void)removePostStdResObject:(REInstaPost *)value;
- (void)addPostStdRes:(NSOrderedSet<REInstaPost *> *)values;
- (void)removePostStdRes:(NSOrderedSet<REInstaPost *> *)values;

@end

NS_ASSUME_NONNULL_END
