//
//  REInstaPostService.m
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//

#import "REInstaPostService.h"

@interface REInstaPostService ()
@property (strong, nonatomic) NSString* clientId;
@property (strong, nonatomic) RKManagedObjectStore* store;
@property (strong, nonatomic) REInstaRKMapper* mapper;
@property (strong, nonatomic) RKObjectManager* objectManager;
@end

@implementation REInstaPostService

-(id)initWithStore:(RKManagedObjectStore *)store
          rkMapper:(REInstaRKMapper*)mapper
   rkObjectManager:(RKObjectManager*)objectManager
      clientId:(NSString*)clientId {
    
    self = [super init];
    if (self) {
        
        self.clientId = clientId;
        self.store = store;
        self.objectManager = objectManager;
        self.mapper = mapper;
    }
    return self;
}


- (void)renewMediaPopularWithProgress:(REProgressBlock)progress success:(RESuccessBlock)success failure:(REFailureBlock)failure {
    
    NSIndexSet* okCodes = RKStatusCodeIndexSetForClass(200);
    RKResponseDescriptor* rd = [RKResponseDescriptor responseDescriptorWithMapping:[_mapper postDeep] method:RKRequestMethodGET pathPattern:nil keyPath:@"data" statusCodes:okCodes];

    NSMutableURLRequest* r = [_objectManager requestWithObject:nil method:RKRequestMethodGET path:@"media/popular" parameters:@{@"client_id" : _clientId}];
    
    RKManagedObjectRequestOperation* op = [[RKManagedObjectRequestOperation alloc] initWithRequest:r responseDescriptors:@[rd]];
    [op.HTTPRequestOperation setDownloadProgressBlock:progress];
    op.managedObjectContext = _store.mainQueueManagedObjectContext;
    op.managedObjectCache = _store.managedObjectCache;
    
    [op setCompletionBlockWithSuccess:^(RKObjectRequestOperation *operation, RKMappingResult *mappingResult) {
        success(mappingResult.array);
    } failure:^(RKObjectRequestOperation *operation, NSError *error) {
        failure(error);
    }];
    
    [_objectManager enqueueObjectRequestOperation:op];
    
}

@end
