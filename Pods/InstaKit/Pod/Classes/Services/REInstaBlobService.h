//
//  REInstaBlobService.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaBlockDefinitions.h"

@protocol InstaImage;
@protocol InstaUser;

/**
 *  @brief  Service that downloads Blobs for InstaModel. Assumes all passed objects
 *          are REInsta* NSManagedObjects from InstaKit. 
 *
 *          TODO: make operations pausable and resumable:
 *          problem - RestKit requires AFHttpNetworking 1.3.4, not 2+.
 *          So I could not find out of the box NSURLSession lib with 
 *          pausable/resumable operations support (RE, 11/15). 
 */
@interface REInstaBlobService : NSObject

/**
 *  @brief  Loads image from 'image.urlString' to 'image.localPath'.
 *          'Renew', instead of 'get' or 'fetch' means - renew on device, load from remote api.
 *          Blocks are called in object's managedObjectContext thread.
 *
 *  @param image    internally REInstaImage.
 *  @param progress progress block.
 *  @param success  'image.localPath' guaranteed to contain path to locally downloaded image.
 *  @param failure  passes a error if download failes.
 *
 *  @return cancellable renew operation.
 */
- (NSOperation *)renewImageBlobFor:(NSObject<InstaImage>*)image withProgress:(REProgressBlock)progress success:(void (^)(NSObject<InstaImage>*))success failure:(REFailureBlock)failure;

/**
 *  @brief  Loads image from 'user.profilePictureUrl' to 'user.profilePictureLocalPath'.
 *          'Renew', instead of 'get' or 'fetch' means - renew on device, load from remote api.
 *          Blocks are called in object's managedObjectContext thread.
 *
 *  @param user     internally REInstaUser.
 *  @param progress progress block.
 *  @param success  'user.profilePictureLocalPath' guaranteed to contain path to locally downloaded image.
 *  @param failure  passes a error if download failes.
 *
 *  @return cancellable renew operation.
 */
- (NSOperation *)renewProfileImageBlobFor:(NSObject<InstaUser>*)user withProgress:(REProgressBlock)progress success:(void (^)(NSObject<InstaUser>*))success failure:(REFailureBlock)failure;

@end
