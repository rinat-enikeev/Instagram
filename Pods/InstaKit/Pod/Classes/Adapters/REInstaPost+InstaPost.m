//
//  REInstaPost+InstaPost.m
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import "REInstaPost+InstaPost.h"

@implementation REInstaPost (InstaPostAdapter)

-(NSDate*)created {
    return [NSDate dateWithTimeIntervalSince1970:[[self createdTimestamp] doubleValue]];
}

@end
