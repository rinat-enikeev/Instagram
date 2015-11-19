//
//  RETableViewController.m
//  STXInstagramFeedView
//
//  Created by Rinat Enikeev on 19/11/15.
//  Copyright © 2015 Rinat Enikeev. All rights reserved.
//

#import "UIViewController+InformUser.h"

@interface UIViewController(InformUser)


// app wide way to inform user (currently TSMessages)
-(void)informUserWithErrorMessage:(NSString*)errorString withTitle:(NSString*)title;
-(void)informUserWithWarnMessage:(NSString*)warningString withTitle:(NSString*)title;
-(void)informUserWithInfoMessage:(NSString*)infoString withTitle:(NSString*)title;
-(void)informUserWithSuccessMessage:(NSString*)successString withTitle:(NSString*)title;

@end
