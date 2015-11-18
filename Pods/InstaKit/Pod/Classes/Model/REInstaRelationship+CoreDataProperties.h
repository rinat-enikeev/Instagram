//
//  REInstaRelationship+CoreDataProperties.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "REInstaRelationship.h"

NS_ASSUME_NONNULL_BEGIN

@interface REInstaRelationship (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *incomingStatus;
@property (nullable, nonatomic, retain) NSString *outgoingStatus;
@property (nullable, nonatomic, retain) REInstaUser *owner;
@property (nullable, nonatomic, retain) REInstaUser *requestedUser;

@end

NS_ASSUME_NONNULL_END
