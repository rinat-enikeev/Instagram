//
//  REInstaComment+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaComment.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaComment (CoreDataProperties)

@property (nullable, nonatomic, retain) NSNumber *createdTimestamp;
@property (nullable, nonatomic, retain) NSString *identifier;
@property (nullable, nonatomic, retain) NSString *text;
@property (nullable, nonatomic, retain) REInstaUser *from;
@property (nullable, nonatomic, retain) REInstaPost *post;

@end

NS_ASSUME_NONNULL_END
