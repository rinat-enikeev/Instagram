//
//  REInstaRKMapper.m
//  Pods
//
//  Created by Rinat Enikeev on 17/11/15.
//
//  http://stackoverflow.com/questions/16395925/restkit-map-values-from-nested-dictionary


#import "REInstaRKMapper.h"
#import "REInstaPost.h"
#import "REInstaUser.h"
#import "REInstaImage.h"

@interface REInstaRKMapper()
@property (nonatomic, strong) RKManagedObjectStore* store;
@property (nonatomic, strong) RKEntityMapping* postDeep;
@property (nonatomic, strong) RKEntityMapping* user;
@property (nonatomic, strong) RKEntityMapping* image;
@property (nonatomic, strong) RKEntityMapping* comment;
@end

@implementation REInstaRKMapper

-(id)initWithRKStore:(RKManagedObjectStore*)store {
    self = [super init];
    if (self) {
        self.store = store;
        
        // ORDER IS IMPORTANT!
        [self mapImage];
        [self mapUser];
        [self mapComment];
        [self mapPostDeep];
    }
    return self;
}

-(void)mapPostDeep {
    
    self.postDeep = [RKEntityMapping mappingForEntityForName:NSStringFromClass([REInstaPost class]) inManagedObjectStore:_store];
    
    // 1. Attributes
    [_postDeep addAttributeMappingsFromDictionary:
        @{
         @"id"             : @"identifier",
         @"comments.count" : @"commentsCount",
         @"likes.count"    : @"likesCount",
         @"created_time"   : @"createdTimestamp",
         @"filter"         : @"filter",
         @"link"           : @"link",
         @"type"           : @"type",
         @"user_has_liked" : @"userHasLiked",
         @"distance"       : @"distance"
         }];
    
    [_postDeep setIdentificationAttributes:@[@"identifier"]];
    
    // 2. Relationships
    RKRelationshipMapping* autorRel = [RKRelationshipMapping relationshipMappingFromKeyPath:@"user" toKeyPath:@"author" withMapping:_user];
    [_postDeep addPropertyMapping:autorRel];
    
    
    RKRelationshipMapping* lowImageMapping = [RKRelationshipMapping relationshipMappingFromKeyPath:@"images.low_resolution" toKeyPath:@"imageLow" withMapping:_image];
    [_postDeep addPropertyMapping:lowImageMapping];
    
    RKRelationshipMapping* thumbImageMapping = [RKRelationshipMapping relationshipMappingFromKeyPath:@"images.thumbnail" toKeyPath:@"imageThumb" withMapping:_image];
    [_postDeep addPropertyMapping:thumbImageMapping];
    
    RKRelationshipMapping* stdImageMapping = [RKRelationshipMapping relationshipMappingFromKeyPath:@"images.standard_resolution" toKeyPath:@"imageStd" withMapping:_image];
    [_postDeep addPropertyMapping:stdImageMapping];
    
    
    RKRelationshipMapping* likersMapping = [RKRelationshipMapping relationshipMappingFromKeyPath:@"likes.data" toKeyPath:@"likers" withMapping:_user];
    [_postDeep addPropertyMapping:likersMapping];
    
    RKRelationshipMapping* commentsMapping = [RKRelationshipMapping relationshipMappingFromKeyPath:@"comments.data" toKeyPath:@"comments" withMapping:_comment];
    [_postDeep addPropertyMapping:commentsMapping];
    
}

// TODO mapPostDeep connections?
//@property (nullable, nonatomic, retain) NSSet<REInstaUser *> *likers;
//@property (nullable, nonatomic, retain) NSOrderedSet<REInstaComment *> *comments;
//@property (nullable, nonatomic, retain) NSSet<REInstaTag *> *tags;
//@property (nullable, nonatomic, retain) REInstaVideo *videoLowBand;
//@property (nullable, nonatomic, retain) REInstaVideo *videoLowRes;
//@property (nullable, nonatomic, retain) REInstaVideo *videoStdRes;
//@property (nullable, nonatomic, retain) REInstaAttribution *attribution;
//@property (nullable, nonatomic, retain) NSSet<REInstaUserOnPost *> *usersOnPost;


-(void)mapUser {
    self.user = [RKEntityMapping mappingForEntityForName:NSStringFromClass([REInstaUser class]) inManagedObjectStore:_store];
    
    [_user addAttributeMappingsFromDictionary:
     @{
       @"id"              : @"identifier",
       @"username"        : @"username",
       @"first_name"      : @"firstName",
       @"last_name"       : @"lastName",
       @"full_name"       : @"fullName",
       @"bio"             : @"bio",
       @"profile_picture" : @"profilePictureUrl",
       @"website"         : @"website",
       @"counts.follows"     : @"followsCount",
       @"counts.followed_by" : @"followedByCount",
       @"counts.media"       : @"mediaCount"
       }];
    
    [_user setIdentificationAttributes:@[@"identifier"]];
}

// TODO mapUser
//@property (nullable, nonatomic, retain) NSSet<REInstaCaption *> *captions;
//@property (nullable, nonatomic, retain) NSSet<REInstaComment *> *comments;
//@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *likes;
//@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *posts;
//@property (nullable, nonatomic, retain) NSSet<REInstaRelationship *> *relationships;
//@property (nullable, nonatomic, retain) NSSet<REInstaRelationship *> *relationshipRequests;
//@property (nullable, nonatomic, retain) NSSet<REInstaUserOnPost *> *onPostPhotos;


-(void)mapImage {
    self.image = [RKEntityMapping mappingForEntityForName:NSStringFromClass([REInstaImage class]) inManagedObjectStore:_store];
    
    [_image addAttributeMappingsFromDictionary:
     @{
       @"height" : @"height",
       @"url"    : @"urlString",
       @"width"  : @"width"
       }];
}

// TODO mapImage
//@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *postLow;
//@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *postStd;
//@property (nullable, nonatomic, retain) NSSet<REInstaPost *> *postThumb;


-(void)mapComment {
    self.comment = [RKEntityMapping mappingForEntityForName:NSStringFromClass([REInstaComment class]) inManagedObjectStore:_store];
    
    [_comment addAttributeMappingsFromDictionary:
     @{
       @"created_time" : @"createdTimestamp",
       @"id"    : @"identifier",
       @"text"  : @"text"
       }];
    
    [_comment setIdentificationAttributes:@[@"identifier"]];
    
    RKRelationshipMapping* autorRel = [RKRelationshipMapping relationshipMappingFromKeyPath:@"from" toKeyPath:@"from" withMapping:_user];
    [_comment addPropertyMapping:autorRel];
    
}

// TODO mapComment
//@property (nullable, nonatomic, retain) REInstaPost *post;


@end
