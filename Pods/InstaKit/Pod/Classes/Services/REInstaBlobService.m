//
//  REInstaBlobService.m
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import "REInstaBlobService.h"
#import <InstaModel/InstaImage.h>

@interface REInstaBlobService ()
@property (strong, nonatomic) NSOperationQueue * operationQueue;
@end
/**
 *  TODO: With Video files you should deal with pausable and resumable
 *        operations. Since RestKit uses AFHttpNetworking 1.3.4
 *        - you can not use AFHttpNetworking. This limits the libs you can use.
 *        Since NSURLConnection is deprecated in iOS 9 - you should probably
 *        wrap ops over NSURLSession or find a lib without AFHttpNetworking.
 */
@implementation REInstaBlobService

-(id)init {
    self = [super init];
    if (self) {
        self.operationQueue = [[NSOperationQueue alloc] init];
    }
    return self;
}
/**
 *  @brief  Download image file via AFHTTPRequestOperation,
 *          save it on disk with UUID path,
 *          set 'localPath' and save 'image' in it's MOC.
 *          After saving 'image' in MOC - call 'success', otherwise 'failure'.
 */
- (NSOperation *)renewImageBlobFor:(NSObject<InstaImage>*)image withProgress:(REProgressBlock)progress success:(void (^)(NSObject<InstaImage>*))success failure:(REFailureBlock)failure {
    
    NSAssert([image isKindOfClass:[REInstaImage class]], @"Passed InstaImage must be kind of REInstaImage class");
    
    NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:image.urlString]];
    
    AFHTTPRequestOperation *operation = [[AFHTTPRequestOperation alloc] initWithRequest:request];
    [operation setDownloadProgressBlock:progress];
    [operation setCompletionBlockWithSuccess:^(AFHTTPRequestOperation *operation, id responseObject)
     {
         NSData* data = (NSData* )responseObject;
         NSString *uuidFilename = [[NSUUID UUID] UUIDString];
         NSError* error = nil;
         [data writeToFile:[self documentsPathForFileName:uuidFilename] options:NSDataWritingAtomic error:&error];

         if (error != nil) {
             NSLog(@"Error downloading image: %@", error);
             if (failure != nil) {
                 failure(error);
             }
         } else {
             REInstaImage* reImage = (REInstaImage*)image; // assertion is on first method line
             reImage.localPath = uuidFilename;
             [reImage.managedObjectContext performBlock:^{
                 NSError* error = nil;
                 [reImage.managedObjectContext saveToPersistentStore:&error];
                 if (error != nil) {
                     NSLog(@"Error downloading image: %@", error);
                     if (failure != nil) {
                         failure(error);
                     }
                 } else {
                     if (success != nil) {
                         success(image);
                     }
                 }
             }];
         }

     }
        failure:^(AFHTTPRequestOperation *operation, NSError *error)
     {
         NSLog(@"Error downloading image: %@", error);
         if (failure != nil) {
             failure(error);
         }
     }];

    [_operationQueue addOperation:operation];
    
    return operation;
}

- (NSOperation *)renewProfileImageBlobFor:(NSObject<InstaUser>*)user withProgress:(REProgressBlock)progress success:(void (^)(NSObject<InstaUser>*))success failure:(REFailureBlock)failure {
 
    NSAssert([user isKindOfClass:[REInstaUser class]], @"Passed InstaUser must be kind of REInstaUser class");
    
    NSURLRequest *request = [NSURLRequest requestWithURL:[NSURL URLWithString:user.profilePictureUrl]];
    
    AFHTTPRequestOperation *operation = [[AFHTTPRequestOperation alloc] initWithRequest:request];
    [operation setDownloadProgressBlock:progress];
    [operation setCompletionBlockWithSuccess:^(AFHTTPRequestOperation *operation, id responseObject)
     {
         NSData* data = (NSData* )responseObject;
         NSString *uuidFilename = [[NSUUID UUID] UUIDString];
         NSError* error = nil;
         [data writeToFile:[self documentsPathForFileName:uuidFilename] options:NSDataWritingAtomic error:&error];
         
         if (error != nil) {
             NSLog(@"Error downloading image: %@", error);
             if (failure != nil) {
                 failure(error);
             }
         } else {
             REInstaUser* reUser = (REInstaUser*)user; // assertion is on first method line
             reUser.profilePictureLocalPath = uuidFilename;
             [reUser.managedObjectContext performBlock:^{
                 NSError* error = nil;
                 [reUser.managedObjectContext saveToPersistentStore:&error];
                 if (error != nil) {
                     NSLog(@"Error downloading image: %@", error);
                     if (failure != nil) {
                         failure(error);
                     }
                 } else {
                     if (success != nil) {
                         success(user);
                     }
                 }
             }];
         }
         
     }
         failure:^(AFHTTPRequestOperation *operation, NSError *error)
     {
         NSLog(@"Error downloading image: %@", error);
         if (failure != nil) {
             failure(error);
         }
     }];
    
    [_operationQueue addOperation:operation];
    
    return operation;
}


- (NSString *)documentsPathForFileName:(NSString *)name
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES);
    NSString *documentsPath = [paths objectAtIndex:0];
    
    return [documentsPath stringByAppendingPathComponent:name];
}

@end