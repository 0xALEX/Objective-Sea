//
//  CommonCrypto+Convenience.h
//  Sleep Diary
//
//  Created by Alexander Ivanov on 14.11.16.
//  Copyright © 2016 Alexander Ivanov. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CommonCrypto/CommonDigest.h>

typedef enum : NSUInteger {
	MD2,
	MD4,
	MD5,
	SHA1,
	SHA224,
	SHA256,
	SHA384,
	SHA512,
} COMMON_DIGEST;

@interface NSData (CommonCrypto)

- (NSData *)hash:(COMMON_DIGEST)commonDigest;

- (NSString *)hashString:(COMMON_DIGEST)commonDigest;

@end

@interface NSString (CommonCrypto)

- (NSData *)hash:(COMMON_DIGEST)commonDigest;

- (NSString *)hashString:(COMMON_DIGEST)commonDigest;

@end
