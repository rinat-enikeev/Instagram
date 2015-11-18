//
//  REInstaComment+InstaComment.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaComment.h"

@protocol InstaComment;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaComment(InstaCommentAdapter) <InstaComment>

@end

NS_ASSUME_NONNULL_END

