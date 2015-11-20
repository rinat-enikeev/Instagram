//
//  UIImageView+Circling.m
//  STXDynamicTableView
//
//  Created by Jesse Armand on 7/2/14.
//  Copyright (c) 2014 2359 Media. All rights reserved.
//

#import "UIImageView+Circling.h"
#import "UIImage+STXImage.h"

#import <objc/runtime.h>

/**
 The `STXRoundedImageCache` protocol is adopted by an object used to cache circled images.
 */
@protocol STXRoundedImageCache <NSObject>

/**
 Returns a circled cached image for the source image.
 
 @param image The source image.
 
 @return The cached circled image.
 */
- (UIImage *)circledImageForImage:(UIImage *)image;

/**
 Caches a particular circled image for the specified image.
 
 @param circledImage The circled image to cache.
 @param image The source image to be used as a cache key.
 */
- (void)cacheCircledImage:(UIImage *)circledImage forImage:(UIImage *)image;
@end

@interface STXImageCache : NSCache <STXRoundedImageCache>
@end

#pragma mark -

static char kSTXSharedImageCacheKey;
static char kSTXCircleImageOperationKey;

@interface UIImageView (_Circling)
@property (readwrite, nonatomic, strong, setter = stx_setCircleImageOperation:) NSOperation *stx_circleImageOperation;
@end

@implementation UIImageView (_Circling)

+ (NSOperationQueue *)stx_sharedCircleImageOperationQueue
{
    static NSOperationQueue *_stx_sharedCircleImageOperationQueue = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _stx_sharedCircleImageOperationQueue = [[NSOperationQueue alloc] init];
        _stx_sharedCircleImageOperationQueue.maxConcurrentOperationCount = NSOperationQueueDefaultMaxConcurrentOperationCount;
    });
    
    return _stx_sharedCircleImageOperationQueue;
}

- (NSOperation *)stx_circleImageOperation
{
    return (NSOperation *)objc_getAssociatedObject(self, &kSTXCircleImageOperationKey);
}

- (void)stx_setCircleImageOperation:(NSOperation *)circleImageOperation
{
    objc_setAssociatedObject(self, &kSTXCircleImageOperationKey, circleImageOperation, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end

@implementation UIImageView (Circling)

+ (id<STXRoundedImageCache>)sharedImageCache {
    static STXImageCache *_stx_defaultImageCache = nil;
    static dispatch_once_t oncePredicate;
    dispatch_once(&oncePredicate, ^{
        _stx_defaultImageCache = [[STXImageCache alloc] init];

        [[NSNotificationCenter defaultCenter] addObserverForName:UIApplicationDidReceiveMemoryWarningNotification object:nil queue:[NSOperationQueue mainQueue] usingBlock:^(NSNotification * __unused notification) {
            [_stx_defaultImageCache removeAllObjects];
        }];
    });

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu"
    return objc_getAssociatedObject(self, &kSTXSharedImageCacheKey) ?: _stx_defaultImageCache;
#pragma clang diagnostic pop
}

+ (void)setSharedImageCache:(id<STXRoundedImageCache>)imageCache {
    objc_setAssociatedObject(self, &kSTXSharedImageCacheKey, imageCache, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)setCircledImageFrom:(UIImage *)sourceImage placeholderImage:(UIImage *)placeholderImage
{
    [self setCircledImageFrom:sourceImage placeholderImage:placeholderImage borderWidth:3];
}

- (void)setCircledImageFrom:(UIImage *)sourceImage placeholderImage:(UIImage *)placeholderImage borderWidth:(CGFloat)borderWidth;
{
    [self cancelCircleImageOperation];
    
    [self addCircleMask];
    
    CGSize imageSize = CGSizeMake(CGRectGetWidth(self.bounds), CGRectGetHeight(self.bounds));
    
    __weak UIImageView *weakSelf = self;
    
    UIImage *cachedImage = [[[self class] sharedImageCache] circledImageForImage:sourceImage];
    if (cachedImage) {
        self.image = cachedImage;
    } else {
        NSOperationQueue *circleImageOperationQueue = [[self class] stx_sharedCircleImageOperationQueue];
        id<STXRoundedImageCache> imageCache = [[self class] sharedImageCache];
        
        self.stx_circleImageOperation = [NSBlockOperation blockOperationWithBlock:^{
            UIImage *circledImage = [sourceImage circleBorderedAtWidth:borderWidth forImageWithSize:imageSize];
            [imageCache cacheCircledImage:circledImage forImage:sourceImage];
            
            __strong __typeof(weakSelf)strongSelf = weakSelf;
            
            if (strongSelf != nil) {
                [[NSOperationQueue mainQueue] addOperationWithBlock:^{
                    strongSelf.image = circledImage;
                }];
            }
        }];
        
        [circleImageOperationQueue addOperation:self.stx_circleImageOperation];
    }
}

- (void)addCircleMask
{
    self.clipsToBounds = YES;
    
    self.backgroundColor = [UIColor whiteColor];
    self.contentMode = UIViewContentModeScaleAspectFill;
    self.layer.cornerRadius = CGRectGetWidth(self.bounds)/2;
    self.layer.masksToBounds = YES;
}

- (void)cancelCircleImageOperation
{
    [self.stx_circleImageOperation cancel];
    self.stx_circleImageOperation = nil;
}

@end

#pragma mark - STXImageCache

/**
 *  Unlike an NSMutableDictionary object, a cache does not copy the key objects that are put into it.
 */
@implementation STXImageCache

- (UIImage *)circledImageForImage:(UIImage *)image {
	return [self objectForKey:image];
}

- (void)cacheCircledImage:(UIImage *)circledImage forImage:(UIImage *)image
{
    if (circledImage && image) {
        [self setObject:circledImage forKey:image];
    }
}

@end
