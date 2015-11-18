//
//  REInstaLocation+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaLocation.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaLocation (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *identifier;
@property (nullable, nonatomic, retain) NSNumber *latitude;
@property (nullable, nonatomic, retain) NSNumber *longitude;
@property (nullable, nonatomic, retain) NSString *name;
@property (nullable, nonatomic, retain) REInstaPost *post;

@end

NS_ASSUME_NONNULL_END
