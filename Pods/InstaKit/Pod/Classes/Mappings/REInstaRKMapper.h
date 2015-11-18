//
//  REInstaRKMapper.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//

#import <Foundation/Foundation.h>

@class RKManagedObjectStore;
@class RKEntityMapping;

@interface REInstaRKMapper : NSObject

@property (nonatomic, strong, readonly) RKEntityMapping* postDeep;

-(id)initWithRKStore:(RKManagedObjectStore*)store;

@end
