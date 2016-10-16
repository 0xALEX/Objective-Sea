//
//  WatchConnectivity+Convenience.m
//  Sleep Diary
//
//  Created by Alexander Ivanov on 13.10.16.
//  Copyright © 2016 Alexander Ivanov. All rights reserved.
//

#import "WatchConnectivity+Convenience.h"

@implementation NSDate (WatchConnectivity)

- (NSString *)serialize {
	return [[NSDateFormatter RFC3339Formatter] stringFromValue:self];
}

+ (NSDate *)deserialize:(NSString *)string {
	return [[NSDateFormatter RFC3339Formatter] dateFromValue:string];
}

@end

@implementation WCSession (Convenience)

- (void)sendMessage:(NSDictionary<NSString *,id> *)message replyHandler:(void (^)(NSDictionary<NSString *,id> * _Nonnull))replyHandler {
	[self sendMessage:message replyHandler:replyHandler errorHandler:^(NSError * _Nonnull error) {
		[error log:@"sendMessage:"];
	}];
}

- (void)sendMessage:(NSDictionary<NSString *,id> *)message {
	[self sendMessage:message replyHandler:Nil errorHandler:^(NSError * _Nonnull error) {
		[error log:@"sendMessage:"];
	}];
}

@end

@implementation WCSessionDelegate

- (void)session:(WCSession *)session didReceiveMessage:(NSDictionary<NSString *,id> *)message {
	if (self.didReceiveMessage)
		self.didReceiveMessage(message, Nil);
}

- (void)session:(WCSession *)session didReceiveMessage:(NSDictionary<NSString *,id> *)message replyHandler:(nonnull void (^)(NSDictionary<NSString *,id> * _Nonnull))replyHandler {
	if (self.didReceiveMessage)
		self.didReceiveMessage(message, replyHandler);
}

@synthesize session = _session;

- (WCSession *)session {
	if (![WCSession isSupported])
		return Nil;

	if (!_session) {
		_session = [WCSession defaultSession];
		_session.delegate = self;
		[_session activateSession];
	}

	return _session;
}

- (WCSession *)installedSession {
	WCSession *session = self.session;

#if TARGET_OS_WATCH
	return session;
#else
	return session.paired && session.watchAppInstalled ? session : Nil;
#endif
}

- (WCSession *)reachableSession {
	WCSession *session = self.session;

	return session.reachable ? session : Nil;
}

static id _instance;

+ (instancetype)instance {
	@synchronized(self) {
		if (!_instance)
			_instance = [self new];
	}

	return _instance;
}

@end
