//
//  REInstaUserOnPost+InstaUserOnPost.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaUserOnPost.h"

@protocol InstaUserOnPost;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaUserOnPost (InstaUserOnPostAdapter) <InstaUserOnPost>

@end

NS_ASSUME_NONNULL_END
