//
//  REInstaPost.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class REInstaAttribution, REInstaCaption, REInstaComment, REInstaImage, REInstaLocation, REInstaTag, REInstaUser, REInstaUserOnPost, REInstaVideo;

NS_ASSUME_NONNULL_BEGIN

@interface REInstaPost : NSManagedObject

// Insert code here to declare functionality of your managed object subclass

@end

NS_ASSUME_NONNULL_END

#import "REInstaPost+CoreDataProperties.h"
