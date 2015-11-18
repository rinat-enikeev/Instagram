//
//  REInstaLocation+InstaLocation.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaLocation.h"

@protocol InstaLocation;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaLocation(InstaLocationAdapter) <InstaLocation>

@end

NS_ASSUME_NONNULL_END
