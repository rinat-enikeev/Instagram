//
//  REInstaCaption+InstaCaption.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaCaption.h"

@protocol InstaCaption;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaCaption(InstaCaptionAdapter) <InstaCaption>

@end

NS_ASSUME_NONNULL_END
