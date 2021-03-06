//
//  NSArray+Convenience.m
//  Sleep Diary
//
//  Created by Alexander Ivanov on 16.10.16.
//  Copyright © 2016 Alexander Ivanov. All rights reserved.
//

#import "NSArray+Convenience.h"

@implementation NSArray (Convenience)

+ (instancetype)arrayWithObject:(id)anObject count:(NSUInteger)count {
	NSMutableArray *array = [NSMutableArray arrayWithCapacity:count];
	for (NSUInteger index = 0; index < count; index++)
		[array addObject:anObject];
	return array;
}

+ (instancetype)arrayWithObject:(id)object1 withObject:(id)object2 {
	return [self arrayWithObject:object1 withObject:object2 withObject:Nil];
}

+ (instancetype)arrayWithObject:(id)object1 withObject:(id)object2 withObject:(id)object3 {
	NSMutableArray *array = [NSMutableArray arrayWithCapacity:3];
	if (object1)
		[array addObject:object1];
	if (object2)
		[array addObject:object2];
	if (object3)
		[array addObject:object3];
	return array;
}

- (NSArray *)arrayWithRange:(NSRange)range {
	return range.location < self.count ? [self subarrayWithRange:NSMakeRange(range.location, (range.location + range.length) < self.count ? range.length : self.count - range.location)] : Nil;
}

- (NSArray *)arrayWithCount:(NSUInteger)count {
	return [self arrayWithRange:NSMakeRange(0, count > self.count ? self.count : count)];
}

- (NSArray *)arrayWithIndex:(NSUInteger)index {
	return index < self.count ? [self arrayWithRange:NSMakeRange(index, self.count - index)] : Nil;
}

- (NSArray *)arrayByAddingObjectsFromNullableArray:(NSArray *)otherArray {
	return otherArray.count ? [self arrayByAddingObjectsFromArray:otherArray] : self;
}

- (NSArray *)arrayByAddingNullableObject:(id)anObject {
	return anObject ? [self arrayByAddingObject:anObject] : self;
}

- (NSArray *)arrayByRemovingObjectsFromArray:(NSArray *)otherArray {
	if (!otherArray)
		return self;

	NSMutableArray *array = [self mutableCopy];
	for (id obj in otherArray)
		[array removeObject:obj];
	return array;
}

- (NSArray *)arrayByRemovingObject:(id)anObject {
	if (!anObject)
		return self;

	NSMutableArray *array = [self mutableCopy];
	[array removeObject:anObject];
	return array;
}

- (NSArray *)arrayByRemovingObjectAtIndex:(NSUInteger)index {
	if (self.count <= index)
		return self;

	NSMutableArray *array = [self mutableCopy];
	[array removeObjectAtIndex:index];
	return array;
}

- (NSArray *)reversedArray {
	NSMutableArray *array = [NSMutableArray arrayWithCapacity:self.count];

	for (NSInteger index = self.count - 1; index >= 0; index--)
		[array addObject:self[index]];

	return array;
}

- (NSArray *)sortedArray:(BOOL)descending {
	return [self sortedArrayUsingComparator:^NSComparisonResult(id obj1, id obj2) {
		return descending ? [obj2 respondsToSelector:@selector(compare:)] ? [obj2 compare:obj1] : NSOrderedSame : [obj1 respondsToSelector:@selector(compare:)] ? [obj1 compare:obj2] : NSOrderedSame;
	}];
}

- (NSArray *)sortedArray {
	return [self sortedArray:NO];
}

- (NSArray *)map:(id (^)(id))predicate {
	NSMutableArray *array = [NSMutableArray arrayWithCapacity:self.count];

	for (id obj in self) {
		id object = predicate ? predicate(obj) : obj;
		if (object)
			[array addObject:object];
	}

	return array;
}

- (NSArray *)query:(BOOL (^)(id))predicate {
	return [self map:predicate ? ^id(id obj) {
		return predicate(obj) ? obj : Nil;
	} : Nil];
}

- (NSUInteger)first:(BOOL (^)(id))predicate {
	NSInteger count = self.count;

	for (NSInteger index = 0; index < count; index++)
		if (!predicate || predicate(self[index]))
			return index;

	return NSNotFound;
}

- (id)firstObject:(BOOL (^)(id))predicate {
	NSUInteger index = [self first:predicate];

	return index == NSNotFound ? Nil : self[index];
}

- (NSUInteger)last:(BOOL (^)(id))predicate {
	NSInteger count = self.count;

	for (NSInteger index = count - 1; index >= 0; index--)
		if (!predicate || predicate(self[index]))
			return index;

	return NSNotFound;
}

- (id)lastObject:(BOOL (^)(id))predicate {
	NSUInteger index = [self last:predicate];

	return index == NSNotFound ? Nil : self[index];
}

- (BOOL)all:(BOOL (^)(id))predicate {
	for (id item in self)
		if (predicate && !predicate(item))
			return NO;

	return YES;
}

- (BOOL)any:(BOOL (^)(id))predicate {
	for (id item in self)
		if (!predicate || predicate(item))
			return YES;

	return NO;
}

- (id)one:(BOOL (^)(id, id))predicate {
	id one = Nil;

	for (id obj in self)
		if (predicate && predicate(one, obj))
			one = obj;

	return one;
}

- (NSDictionary *)dictionaryWithKey:(id<NSCopying>(^)(id))keyPredicate value:(id(^)(id, id<NSCopying>, id))valPredicate  {
	NSMutableDictionary *dictionary = [NSMutableDictionary dictionaryWithCapacity:self.count];

	for (id obj in self) {
		id<NSCopying> key = keyPredicate ? keyPredicate(obj) : obj;
		if (key) {
			id val = dictionary[key];
			val = valPredicate ? valPredicate(obj, key, val) : obj;
			dictionary[key] = val;
		}
	}

	return dictionary;
}

- (NSDictionary *)dictionaryWithKey:(id<NSCopying>(^)(id))keyPredicate {
	return [self dictionaryWithKey:keyPredicate value:Nil];
}

+ (instancetype)arrayFromRange:(NSRange)range block:(id (^)(NSUInteger))block {
	NSMutableArray *array = [NSMutableArray arrayWithCapacity:range.length];

	NSUInteger count = range.location + range.length;
	for (NSUInteger index = range.location; index < count; index++) {
		id object = block ? block(index) : @(index);
		if (object)
			[array addObject:object];
	}

	return array;
}

+ (instancetype)arrayFromCount:(NSUInteger)count block:(id (^)(NSUInteger))block {
	return [self arrayFromRange:NSMakeRange(0, count) block:block];
}

- (NSString *)componentsJoinedByString:(NSString *)separator block:(NSString *(^)(id))block {
	NSMutableString *description = [[NSMutableString alloc] init];

	for (NSUInteger index = 0; index < self.count; index++) {
		if (index > 0 && separator.length)
			[description appendString:separator];

		NSString *string = block ? block(self[index]) : [self[index] description];
		if (string)
			[description appendString:string];
	}

	return description;
}

- (BOOL)isEqualToArray:(NSArray *)otherArray block:(BOOL(^)(id, id))predicate {
	if (self.count != otherArray.count)
		return NO;

	for (NSUInteger index = 0; index < self.count; index++)
		if (!predicate(self[index], otherArray[index]))
			return NO;

	return YES;
}

- (id)randomObject {
	if (self.count == 0)
		return Nil;

	if (self.count == 1)
		return [self objectAtIndex:0];

	NSUInteger index = arc4random() % self.count;
	return [self objectAtIndex:index];
}

@end

@implementation NSMutableArray (Convenience)

- (id)fifo {
	if (!self.count)
		return Nil;

	id obj = self.firstObject;
	[self removeObjectAtIndex:0];
	return obj;
}

- (id)lifo {
	if (!self.count)
		return Nil;

	id obj = self.lastObject;
	[self removeObjectAtIndex:self.count - 1];
	return obj;
}

@end
