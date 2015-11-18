//
//  InstaLocation.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#ifndef InstaLocation_h
#define InstaLocation_h

@import Foundation;

@protocol InstaPost;

@protocol InstaLocation <NSObject>

@property (nullable, nonatomic, retain, readonly) NSString *identifier;
@property (nullable, nonatomic, retain, readonly) NSNumber *latitude;
@property (nullable, nonatomic, retain, readonly) NSNumber *longitude;
@property (nullable, nonatomic, retain, readonly) NSString *name;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaPost> *post;

@end


#endif /* InstaLocation_h */
