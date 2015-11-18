//
//  InstaKit.m
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//

#import "InstaKit.h"
#import "Mappings/REInstaRKMapper.h"


NSString *const kInstagramBaseUrl = @"https://api.instagram.com/v1/";

@interface InstaKit ()
@property (strong, nonatomic) NSString* clientId;
@property (strong, nonatomic) RKManagedObjectStore* store;
@property (strong, nonatomic) REInstaRKMapper* mapper;
@property (strong, nonatomic) RKObjectManager* objectManager;

// services
@property (strong, nonatomic) REInstaPostService* postService;
@property (strong, nonatomic) REInstaBlobService* blobService;

@end

@implementation InstaKit

-(id)initWithClientId:(NSString* )clientId dbFileName:(NSString *)dbFileName {
    self = [super init];
    if (self) {
        
        // 1. Client
        self.clientId = clientId;
        
        // 2. Store
        NSBundle* mainBundle = [NSBundle bundleForClass:[self class]];
        
        NSBundle* bundle = [NSBundle bundleWithPath:[[mainBundle bundlePath] stringByAppendingPathComponent:@"InstaKit.bundle"]];
        NSURL* modelUrl = [bundle URLForResource:@"REInstaKitModel" withExtension:@"momd"];
        NSManagedObjectModel* model = [[NSManagedObjectModel alloc] initWithContentsOfURL:modelUrl];
        self.store = [[RKManagedObjectStore alloc] initWithManagedObjectModel:model];
        [self initializeRestKitStore:_store withDbName:dbFileName];
        
        // 3. Object manager
        self.objectManager = [RKObjectManager managerWithBaseURL:[NSURL URLWithString:kInstagramBaseUrl]];
        _objectManager.requestSerializationMIMEType = RKMIMETypeJSON;
        _objectManager.managedObjectStore = _store;
        
        // 4. Mapper
        self.mapper = [[REInstaRKMapper alloc] initWithRKStore:_store];
        
        // 5. Services
        self.postService = [[REInstaPostService alloc] initWithStore:_store rkMapper:_mapper rkObjectManager:_objectManager clientId:_clientId];
        
        self.blobService = [[REInstaBlobService alloc] init];
        
    }
    return self;
}

-(void)initializeRestKitStore:(RKManagedObjectStore*)store withDbName:(NSString *)dbName {
    NSError* error = nil;
    BOOL success = RKEnsureDirectoryExistsAtPath(RKApplicationDataDirectory(), &error);
    if (!success) {
        NSLog(@"Failed to create Application Data Directory at path '%@': %@", RKApplicationDataDirectory(), error);
    }
    NSString *path = [RKApplicationDataDirectory() stringByAppendingPathComponent:dbName];
    NSPersistentStore* persistentStore = [store addSQLitePersistentStoreAtPath:path fromSeedDatabaseAtPath:nil withConfiguration:nil options:nil error:&error];
    if (!persistentStore) {
        NSLog(@"Failed adding persistent store at path '%@': %@", path,  error);
    }
    
    [store createManagedObjectContexts];
}

@end
