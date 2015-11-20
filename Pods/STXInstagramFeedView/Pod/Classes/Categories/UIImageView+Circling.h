//
//  UIImageView+Masking.h
//  STXDynamicTableView
//
//  Created by Jesse Armand on 7/2/14.
//  Modified by Rinat Enikeev 11/17/15.
//  Copyright (c) 2014 2359 Media. All rights reserved.
//

@interface UIImageView (Circling)

- (void)setCircledImageFrom:(UIImage *)sourceImage placeholderImage:(UIImage *)placeholderImage;

- (void)setCircledImageFrom:(UIImage *)sourceImage placeholderImage:(UIImage *)placeholderImage borderWidth:(CGFloat)borderWidth;

@end
