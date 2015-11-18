//
//  REInstaAttribution+InstaAttribution.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaAttribution.h"

@protocol InstaAttribution;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaAttribution(InstaAttributionAdapter) <InstaAttribution>

@end

NS_ASSUME_NONNULL_END