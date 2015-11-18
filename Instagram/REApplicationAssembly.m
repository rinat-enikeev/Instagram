//
//  REApplicationAssembly.m
//  Instagram
//
//  Created by Rinat Enikeev on 19/11/15.
//  Copyright © 2015 Rinat Enikeev. All rights reserved.
//

#import "REApplicationAssembly.h"
#import <InstaKit/InstaKit.h>

@implementation REApplicationAssembly

#pragma mark - Config
- (id)config
{
    return [TyphoonDefinition configDefinitionWithName:@"Configuration.plist"];
}

#pragma mark - Kits
- (InstaKit *)instaKit
{
    return [TyphoonDefinition withClass:[InstaKit class] configuration:^(TyphoonDefinition *definition)
        {
            [definition useInitializer:@selector(initWithClientId:dbFileName:) parameters:^(TyphoonMethod *initializer)
             {
                 [initializer injectParameterWith:TyphoonConfig(@"InstagramClientID")];
                 [initializer injectParameterWith:TyphoonConfig(@"InstagramDbFileName")];
             }];
            definition.scope = TyphoonScopeSingleton;
        }];
}

@end
