//
//  UIApplication+Convenience.h
//  Ringtonic
//
//  Created by Alexander Ivanov on 06.10.16.
//  Copyright © 2016 Alexander Ivanov. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "NSArray+Convenience.h"

#define kAppITunes @"itunes"
#define kAppMusic @"music"

#define UIApplicationStateString(applicationState) ((applicationState) == UIApplicationStateActive ? @"Active" : (applicationState) == UIApplicationStateInactive ? @"Inactive" : (applicationState) == UIApplicationStateBackground ? @"Background" : @"")

#define NSURLWithTel(tel) [NSURL URLWithString:tel ? [NSString stringWithFormat:@"tel:%@", [[tel componentsSeparatedByCharactersInSet:[[NSCharacterSet characterSetWithCharactersInString:@"1234567890+"] invertedSet]] componentsJoinedByString:@""]] : @"tel"]

#define IOS_10_0 __has_include(<UserNotifications/UNUserNotificationCenter.h>)

@interface UIApplication (Convenience)

+ (void)openURL:(NSURL *)url options:(NSDictionary<NSString *, id> *)options completionHandler:(void (^)(BOOL success))completion;
+ (void)openURL:(NSURL *)url;
+ (void)openSettings;
//+ (void)openRingtone;
+ (void)openURL:(NSURL *)url inApp:(NSString *)app;

@property (strong, nonatomic) __kindof UIViewController *rootViewController;

@property (assign, nonatomic, readonly) BOOL iPad;
@property (assign, nonatomic, readonly) BOOL iPhone;

@property (assign, nonatomic, readonly) CGFloat statusBarHeight;

@property (assign, nonatomic, readonly) BOOL isActive;
@property (assign, nonatomic, readonly) BOOL isBackground;
@property (assign, nonatomic, readonly) BOOL isInactive;

+ (BOOL)performBackgroundTaskWithName:(NSString *)taskName handler:(void (^)(void))taskHandler expirationHandler:(void (^)(void))expirationHandler;

+ (void)setAlternateIconName:(NSString *)alternateIconName;

@end
