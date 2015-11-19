//
//  InstagramUITests.m
//  InstagramUITests
//
//  Created by Rinat Enikeev on 19/11/15.
//  Copyright © 2015 Rinat Enikeev. All rights reserved.
//

#import <XCTest/XCTest.h>

@interface InstagramUITests : XCTestCase

@end

@implementation InstagramUITests

- (void)setUp {
    [super setUp];
    
    self.continueAfterFailure = NO;
    [[[XCUIApplication alloc] init] launch];
}

- (void)tearDown {
    [super tearDown];
}

- (void)test {
    // You should probably add some integration test.
    // Testing modules (even UI) should be done in relevant pods. 
}


@end
