//
//  InstaRelationship.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#ifndef InstaRelationship_h
#define InstaRelationship_h


@import Foundation;

@protocol InstaUser;

@protocol InstaRelationship <NSObject>

@property (nullable, nonatomic, retain, readonly) NSString *outgoingStatus;
@property (nullable, nonatomic, retain, readonly) NSString *incomingStatus;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaUser> *owner;
@property (nullable, nonatomic, retain, readonly) NSObject<InstaUser> *requestedUser;

@end


#endif /* InstaRelationship_h */
