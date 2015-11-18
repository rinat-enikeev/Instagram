//
//  REInstaPost+InstaPost.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaPost.h"

@protocol InstaPost;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaPost (InstaPostAdapter) <InstaPost>

@end

NS_ASSUME_NONNULL_END