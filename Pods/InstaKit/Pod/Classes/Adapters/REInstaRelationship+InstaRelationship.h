//
//  REInstaRelationship+InstaRelationship.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaRelationship.h"

@protocol InstaRelationship;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaRelationship (InstaRelationshipAdapter) <InstaRelationship>

@end

NS_ASSUME_NONNULL_END

