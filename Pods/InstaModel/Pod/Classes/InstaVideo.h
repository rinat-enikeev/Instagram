//
//  InstaVideo.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#ifndef InstaVideo_h
#define InstaVideo_h

@import Foundation;

@protocol InstaPost;

@protocol InstaVideo <NSObject>

@property (nullable, nonatomic, retain, readonly) NSNumber *height;
@property (nullable, nonatomic, retain, readonly) NSString *localPath;
@property (nullable, nonatomic, retain, readonly) NSString *url;
@property (nullable, nonatomic, retain, readonly) NSNumber *width;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaPost> *> *postLowBand;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaPost> *> *postLowRes;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaPost> *> *postStdRes;

@end

#endif /* InstaVideo_h */
