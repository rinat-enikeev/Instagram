//
//  InstaTag.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#ifndef InstaTag_h
#define InstaTag_h


@import Foundation;

@protocol InstaPost;

@protocol InstaTag <NSObject>

@property (nullable, nonatomic, retain, readonly) NSString *name;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaPost> *> *posts;

@end


#endif /* InstaTag_h */
