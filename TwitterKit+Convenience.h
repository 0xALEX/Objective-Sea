//
//  TwitterKit+Convenience.h
//  Ringtonic
//
//  Created by Alexander Ivanov on 29.05.17.
//  Copyright © 2017 Alexander Ivanov. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <TwitterKit/TwitterKit.h>

@interface TWComposer : NSObject
@property (strong, nonatomic) NSString *text;
@property (strong, nonatomic) UIImage *image;
@property (strong, nonatomic) NSURL *URL;

- (void)showFromViewController:(UIViewController *)fromController completion:(TWTRComposerCompletion)completion;
@end

@interface TWTRAPIClient (Convenience)

- (NSProgress *)sendTwitterRequestWithMethod:(NSString *)method URL:(NSString *)URLString parameters:(NSDictionary *)parameters completion:(TWTRNetworkCompletion)completion;

@end
