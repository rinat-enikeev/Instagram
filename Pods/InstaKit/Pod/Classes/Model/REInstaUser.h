//
//  REInstaUser.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class REInstaCaption, REInstaComment, REInstaPost, REInstaRelationship, REInstaUserOnPost;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaUser : NSManagedObject

@end

NS_ASSUME_NONNULL_END

#import "REInstaUser+CoreDataProperties.h"
