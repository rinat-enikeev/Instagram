//
//  REInstaCaption+InstaCaption.m
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#import "REInstaCaption+InstaCaption.h"

@implementation REInstaCaption(InstaCaptionAdapter)

-(NSDate*)created {
    return [NSDate dateWithTimeIntervalSince1970:[[self createdTimestamp] doubleValue]];
}

@end
