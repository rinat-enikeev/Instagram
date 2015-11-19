//
//  RETableViewController.m
//  STXInstagramFeedView
//
//  Created by Rinat Enikeev on 19/11/15.
//  Copyright © 2015 Rinat Enikeev. All rights reserved.
//

#import "UIViewController+InformUser.h"
#import <TSMessages/TSMessage.h>

@implementation UIViewController(InformUser)

-(void)informUserWithErrorMessage:(NSString*)errorString withTitle:(NSString*)title {
    [TSMessage showNotificationWithTitle:title
                                subtitle:errorString
                                    type:TSMessageNotificationTypeError];
}

-(void)informUserWithWarnMessage:(NSString*)warningString withTitle:(NSString*)title {
    [TSMessage showNotificationWithTitle:title
                                subtitle:warningString
                                    type:TSMessageNotificationTypeWarning];
}

-(void)informUserWithInfoMessage:(NSString*)infoString withTitle:(NSString*)title {
    [TSMessage showNotificationWithTitle:title
                                subtitle:infoString
                                    type:TSMessageNotificationTypeMessage];
}

-(void)informUserWithSuccessMessage:(NSString*)successString withTitle:(NSString*)title {
    [TSMessage showNotificationWithTitle:title
                                subtitle:successString
                                    type:TSMessageNotificationTypeSuccess];
}

@end
