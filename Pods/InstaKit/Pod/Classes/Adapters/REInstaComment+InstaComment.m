//
//  REInstaComment+InstaComment.m
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import "REInstaComment+InstaComment.h"

@implementation REInstaComment(InstaCommentAdapter)

-(NSDate*)created {
    return [NSDate dateWithTimeIntervalSince1970:[[self createdTimestamp] doubleValue]];
}


@end
