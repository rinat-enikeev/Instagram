//
//  InstaKit.h
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//

#import <Foundation/Foundation.h>
#import "REInstaPostService.h"
#import "REInstaBlobService.h"

@interface InstaKit : NSObject

@property (strong, nonatomic, readonly) REInstaPostService* postService;
@property (strong, nonatomic, readonly) REInstaBlobService* blobService;

-(id)initWithClientId:(NSString* )clientId dbFileName:(NSString *)dbFileName;

@end
