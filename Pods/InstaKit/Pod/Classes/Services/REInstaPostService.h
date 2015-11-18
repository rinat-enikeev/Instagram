//
//  REInstaPostService.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaBlockDefinitions.h"
#import "REInstaRKMapper.h"

@class RKManagedObjectStore;
@class RKObjectManager;

@interface REInstaPostService : NSObject

-(id)initWithStore:(RKManagedObjectStore *)store
        rkMapper:(REInstaRKMapper*)mapper
            rkObjectManager:(RKObjectManager*)objectManager
               clientId:(NSString*)clientId;

/**
 *  @brief  Loads most recent media popular posts from Instagram.
 *
 *  @param progress download progress (in bytes).
 *  @param success  returns an array of popular NSObject<InstaPost>.
 *  @param failure  returns a error, if present. 
 */
- (void)renewMediaPopularWithProgress:(REProgressBlock)progress success:(RESuccessBlock)success failure:(REFailureBlock)failure;

@end
