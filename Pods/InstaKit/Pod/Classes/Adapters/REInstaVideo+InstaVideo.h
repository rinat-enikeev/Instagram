//
//  REInstaVideo+InstaVideo.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaVideo.h"

@protocol InstaVideo;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaVideo (InstaVideoAdapter) <InstaVideo>

@end

NS_ASSUME_NONNULL_END

