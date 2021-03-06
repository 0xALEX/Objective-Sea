//
//  NSURL+Convenience.h
//  Crowd Guard
//
//  Created by Alexander Ivanov on 17.11.16.
//  Copyright © 2016 Alexander Ivanov. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NSObject+Convenience.h"

#define URL_SCHEME_HTTP @"http"
#define URL_SCHEME_HTTPS @"https"

#define URL_SCHEME_IPOD_LIBRARY @"ipod-library"

@interface NSURL (Convenience)

+ (instancetype)URLWithFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

+ (NSURL *)urlWithScheme:(NSString *)scheme andParameters:(NSDictionary *)parameters;

- (NSDictionary *)queryDictionary;

- (NSURL *)URLByAppendingQueryDictionary:(NSDictionary *)dictionary allowedCharacters:(NSCharacterSet *)allowedCharacters;
- (NSURL *)URLByAppendingQueryDictionary:(NSDictionary *)dictionary;

@property (assign, nonatomic, readonly) BOOL isWebAddress;
@property (assign, nonatomic, readonly) BOOL isMediaItem;

- (NSString *)lastPathComponentWithoutExtension;
- (NSURL *)URLByAppendingPathComponents:(NSArray<NSString *> *)pathComponents;
- (NSURL *)URLByChangingPathExtension:(NSString *)extension;
- (NSURL *)URLByChangingPath:(NSURL *)path;

@end
