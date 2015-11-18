//
//  REInstaImage+InstaImage.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaImage.h"

@protocol InstaImage;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaImage(InstaImageAdapter) <InstaImage>

@end

NS_ASSUME_NONNULL_END
