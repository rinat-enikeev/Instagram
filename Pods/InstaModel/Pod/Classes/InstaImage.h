//
//  InstaImage.h
//  Pods
//
//  Created by Rinat Enikeev on 18/11/15.
//
//

#ifndef InstaImage_h
#define InstaImage_h

@import Foundation;

@protocol InstaPost;

@protocol InstaImage <NSObject>

@property (nullable, nonatomic, retain, readonly) NSNumber *height;
@property (nullable, nonatomic, retain, readonly) NSString *localPath;
@property (nullable, nonatomic, retain, readonly) NSString *urlString;
@property (nullable, nonatomic, retain, readonly) NSNumber *width;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaPost> *> *postLow;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaPost> *> *postStd;
@property (nullable, nonatomic, retain, readonly) NSOrderedSet<NSObject<InstaPost> *> *postThumb;

@end

#endif /* InstaImage_h */
