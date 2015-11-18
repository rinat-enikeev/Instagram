//
//  REInstaUser+InstaUser.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaUser.h"

@protocol InstaUser;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaUser (InstaUserAdapter) <InstaUser>

@end

NS_ASSUME_NONNULL_END
