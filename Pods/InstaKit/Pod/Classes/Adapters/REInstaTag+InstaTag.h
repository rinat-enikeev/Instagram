//
//  REInstaTag+InstaTag.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaTag.h"

@protocol InstaTag;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaTag (InstaTagAdapter) <InstaTag>

@end

NS_ASSUME_NONNULL_END
