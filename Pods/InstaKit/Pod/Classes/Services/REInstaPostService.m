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
@property (strong, nonatomic) NSString* postEntityName;
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
        self.postEntityName = NSStringFromClass([REInstaPost class]);
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
        
        [self.store.mainQueueManagedObjectContext performBlock:^{
            NSError* error = nil;
            [self.store.mainQueueManagedObjectContext saveToPersistentStore:&error];
            if (error != nil) {
                NSLog(@"Error saving renewed popular posts: %@", error);
                if (failure != nil) {
                    failure(error);
                }
            } else {
                if (success != nil) {
                    success(mappingResult.array);
                }
            }
        }];
        
    } failure:^(RKObjectRequestOperation *operation, NSError *error) {
        if (failure != nil) {
            failure(error);
        }
    }];
    
    [_objectManager enqueueObjectRequestOperation:op];
    
}

-(NSArray<NSObject<InstaPost>*> *)fetchPostsWithPredicate:(NSPredicate*)predicate
                                          sortDescriptors:(NSArray<NSSortDescriptor *>*)sortDescriptors
                                                    limit:(NSUInteger)limit error:(NSError**)error{
    NSManagedObjectContext* moc = _store.mainQueueManagedObjectContext;
    NSFetchRequest *r = [NSFetchRequest fetchRequestWithEntityName:self.postEntityName];
    r.predicate = predicate;
    r.sortDescriptors = sortDescriptors;
    [r setFetchLimit:limit];
    
    NSError* fetchError = nil;
    NSArray *results = [moc executeFetchRequest:r error:&fetchError];
    
    if (fetchError != nil && error != NULL) { // check to avoid crash if **error is not provided
        *error = fetchError;
    }
    
    return results;
}

@end
