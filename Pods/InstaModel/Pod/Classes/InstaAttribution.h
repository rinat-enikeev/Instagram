//
//  InstaAttribution.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#ifndef InstaAttribution_h
#define InstaAttribution_h


@import Foundation;

@protocol InstaPost;

@protocol InstaAttribution <NSObject>

@property (nullable, nonatomic, retain, readonly) NSString *name;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaPost> *> *posts;

@end

#endif /* InstaAttribution_h */
