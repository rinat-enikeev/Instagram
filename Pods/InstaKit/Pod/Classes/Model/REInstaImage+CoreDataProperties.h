//
//  REInstaImage+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaImage.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaImage (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *height;
@property (nullable, nonatomic, retain) NSString *localPath;
@property (nullable, nonatomic, retain) NSString *urlString;
@property (nullable, nonatomic, retain) NSNumber *width;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaPost *> *postLow;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaPost *> *postStd;
@property (nullable, nonatomic, retain) NSOrderedSet<REInstaPost *> *postThumb;

@end

@interface REInstaImage (CoreDataGeneratedAccessors)

- (void)insertObject:(REInstaPost *)value inPostLowAtIndex:(NSUInteger)idx;
- (void)removeObjectFromPostLowAtIndex:(NSUInteger)idx;
- (void)insertPostLow:(NSArray<REInstaPost *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removePostLowAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInPostLowAtIndex:(NSUInteger)idx withObject:(REInstaPost *)value;
- (void)replacePostLowAtIndexes:(NSIndexSet *)indexes withPostLow:(NSArray<REInstaPost *> *)values;
- (void)addPostLowObject:(REInstaPost *)value;
- (void)removePostLowObject:(REInstaPost *)value;
- (void)addPostLow:(NSOrderedSet<REInstaPost *> *)values;
- (void)removePostLow:(NSOrderedSet<REInstaPost *> *)values;

- (void)insertObject:(REInstaPost *)value inPostStdAtIndex:(NSUInteger)idx;
- (void)removeObjectFromPostStdAtIndex:(NSUInteger)idx;
- (void)insertPostStd:(NSArray<REInstaPost *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removePostStdAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInPostStdAtIndex:(NSUInteger)idx withObject:(REInstaPost *)value;
- (void)replacePostStdAtIndexes:(NSIndexSet *)indexes withPostStd:(NSArray<REInstaPost *> *)values;
- (void)addPostStdObject:(REInstaPost *)value;
- (void)removePostStdObject:(REInstaPost *)value;
- (void)addPostStd:(NSOrderedSet<REInstaPost *> *)values;
- (void)removePostStd:(NSOrderedSet<REInstaPost *> *)values;

- (void)insertObject:(REInstaPost *)value inPostThumbAtIndex:(NSUInteger)idx;
- (void)removeObjectFromPostThumbAtIndex:(NSUInteger)idx;
- (void)insertPostThumb:(NSArray<REInstaPost *> *)value atIndexes:(NSIndexSet *)indexes;
- (void)removePostThumbAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectInPostThumbAtIndex:(NSUInteger)idx withObject:(REInstaPost *)value;
- (void)replacePostThumbAtIndexes:(NSIndexSet *)indexes withPostThumb:(NSArray<REInstaPost *> *)values;
- (void)addPostThumbObject:(REInstaPost *)value;
- (void)removePostThumbObject:(REInstaPost *)value;
- (void)addPostThumb:(NSOrderedSet<REInstaPost *> *)values;
- (void)removePostThumb:(NSOrderedSet<REInstaPost *> *)values;

@end

NS_ASSUME_NONNULL_END
