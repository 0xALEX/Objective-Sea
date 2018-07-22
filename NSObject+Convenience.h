//
//  NSLib.h
//  Done!
//
//  Created by Alexander Ivanov on 17.10.13.
//  Copyright (c) 2013 Alex Ivanov. All rights reserved.
//

#import <Foundation/Foundation.h>

#define cls(cls, obj) ((cls *)[obj cast:[cls class]])

#define arr_(obj) ({ __typeof__(obj) __obj = (obj); __obj ? @[ __obj ] : Nil; })
#define arr__(obj0, obj1) ({ __typeof__(obj0) __obj0 = (obj0); __typeof__(obj1) __obj1 = (obj1); __obj0 && __obj1 ? @[ __obj0, __obj1 ] : __obj0 ? @[ __obj0 ] : __obj1 ? @[ __obj1 ] : Nil; })
//#define arr___(obj0, obj1, obj2) ({ __typeof__(obj0) __obj0 = (obj0); __typeof__(obj1) __obj1 = (obj1); __typeof__(obj2) __obj2 = (obj2); !__obj0 ? arr__(__obj1, __obj2) : !__obj1 ? arr__(__obj0, __obj2) : !__obj2 ? arr__(__obj0, __obj1) : @[ __obj0, __obj1, __obj2 ]; })
#define idx(arr, idx) ({ __typeof__(arr) __arr = (arr); NSUInteger __len = [__arr count]; NSInteger __idx = (idx); __idx >= 0 && __idx < __len ? [__arr objectAtIndex:__idx] : __idx < 0 && -__idx <= __len ? [__arr objectAtIndex:__len + __idx] : Nil; })

#define dic_(key0, val0) ({ __typeof__(key0) __key0 = (key0); __typeof__(val0) __val0 = (val0); __key0 && __val0 ? @{ __key0 : __val0 } : Nil; })
#define dic__(key0, val0, key1, val1) ({ __typeof__(key0) __key0 = (key0); __typeof__(val0) __val0 = (val0); __typeof__(key1) __key1 = (key1); __typeof__(val1) __val1 = (val1); __key0 && __val0 && __key1 && __val1 ? @{ __key0 : __val0, __key1 : __val1 } : __key0 && __val0 ? @{ __key0 : __val0 } : __key1 && __val1 ? @{ __key1 : __val1 } : Nil; })

#define ret(obj, sel) ({ id __obj = (obj); [__obj respondsToSelector:@selector(sel)] ? [__obj performSelector:@selector(sel)] : Nil; })
#define ret_(obj, sel, arg) ({ id __obj = (obj); id __arg= (arg); [__obj respondsToSelector:@selector(sel)] ? [__obj performSelector:@selector(sel) withObject:__arg] : Nil; })
#define ret__(obj, sel, arg1, arg2) ({ id __obj = (obj); id __arg1 = (arg1); id __arg2 = (arg2); [__obj respondsToSelector:@selector(sel)] ? [__obj performSelector:@selector(sel) withObject:__arg1 withObject:__arg2] : Nil; })

#define sel(obj, sel) ({ id __obj = (obj); if ([__obj respondsToSelector:@selector(sel)]) { [__obj performSelector:@selector(sel)]; } })
#define sel_(obj, sel, arg) ({ id __obj = (obj); id __arg= (arg); if ([__obj respondsToSelector:@selector(sel)]) { [__obj performSelector:@selector(sel) withObject:__arg]; } })
#define sel__(obj, sel, arg1, arg2) ({ id __obj = (obj); id __arg1 = (arg1); id __arg2 = (arg2); if ([__obj respondsToSelector:@selector(sel)]) { [__obj performSelector:@selector(sel) withObject:__arg1 withObject:__arg2]; } })

#define NOW(var) NSDate *var = [NSDate date]

#define __property(type, name, init) - (type)name { if (!_##name) { _##name = init; } return _##name; }
#define __synthesize(type, name, init) @synthesize name = _##name; - (type)name { if (!_##name) { _##name = init; } return _##name; }
#define __static(type, name, init) static type _##name; + (type)name { @synchronized(self) { if (!_##name) _##name = init; } return _##name; }

#define __class(type, get, set) static type _##get; + (type)get { return _##get; } + (void)set:(type)get { _##get = get; }

#define LNG_RU @"ru"

#define STR_ASTERISK @"*"
#define STR_AMPERSAND @"&"
#define STR_COLON @":"
#define STR_COMMA @","
#define STR_DOT @"."
#define STR_EMPTY @""
#define STR_EQUALITY @"="
#define STR_HYPHEN @"-"
#define STR_NEW_LINE @"\n"
#define STR_NULL @"\0"
#define STR_NUMBER @"#"
#define STR_PLUS @"+"
#define STR_SEMICOLON @";"
#define STR_SLASH @"/"
#define STR_SPACE @" "
#define STR_UNDERSCORE @"_"
#define STR_VERTICAL_BAR @"|"

#define DIV_FLOOR(a, b) a / b
#define DIV_CEIL(a, b) (a + b - 1) / b
#define DIV_ROUND(a, b) (a + b / 2) / b

#define FLT_EQUALS(x, y) ({ float __x = (x); float __y = y; fabsf(__x - __y) < FLT_EPSILON; })
#define DBL_EQUALS(x, y) ({ double __x = (x); double __y = y; fabs(__x - __y) < DBL_EPSILON; })

#define loc(key) NSLocalizedString(key, Nil)
#define NSLocalizedMethod(method, key) + (NSString *)method { return NSLocalizedString(key, Nil); }

#define NSDateIsEqualToDate(d1, d2) ({ NSDate *__d1 = (d1); NSDate *__d2 = (d2); __d1 == __d2 || (__d2 != Nil && [__d1 isEqualToDate:__d2]); })
#define NSNumberIsEqualToNumber(n1, n2) ({ NSNumber *__n1 = (n1); NSNumber *__n2 = (n2); __n1 == __n2 || (__n2 != Nil && [__n1 isEqualToNumber:__n2]); })
#define NSStringIsEqualToString(s1, s2) ({ NSString *__s1 = (s1); NSString *__s2 = (s2); __s1 == __s2 || (__s2 != Nil && [__s1 isEqualToString:__s2]); })
/*
 #define NSDateEqualToDate(d1, d2) (d1 == d2 || [d1 isEqualToDate:d2])
 #define NSNumberEqualToNumber(n1, n2) (n1 == n2 || [n1 isEqualToNumber:n2])
 #define NSStringEqualToString(s1, s2) (s1 == s2 || [s1 isEqualToString:s2])
 */
#define NSDateCompareToDate(d1, d2) (d1 == d2 ? NSOrderedSame : d1 == Nil ? NSOrderedAscending : d2 == Nil ? NSOrderedDescending : [d1 compare:d2])
#define NSNumberCompareToNumber(n1, n2) (n1 == n2 ? NSOrderedSame : n1 == Nil ? NSOrderedAscending : n2 == Nil ? NSOrderedDescending : [n1 compare:n2])
#define NSStringCompareToString(s1, s2) (s1 == s2 ? NSOrderedSame : s1 == Nil ? NSOrderedAscending : s2 == Nil ? NSOrderedDescending : [s1 compare:s2])

#define MEM_PAGE_SIZE 4096

#ifdef DEBUG
#define IS_DEBUGGING YES
#else
#define IS_DEBUGGING NO
#endif

#if (TARGET_IPHONE_SIMULATOR)
#define IS_SIMULATOR YES
#else
#define IS_SIMULATOR NO
#endif

#define str(d) [NSString stringWithFormat:@"%ld", (long)d]
#define fstr(f) [NSString stringWithFormat:@"%f", (double)f]

#define DEG_360 (2.0 * M_PI)

#define VER(major, minor) [[NSProcessInfo processInfo] isOperatingSystemAtLeastVersion:(NSOperatingSystemVersion){ major, minor }]

@interface NSObject (Convenience)

- (id)cast:(Class)type;

- (void)log:(NSString *)message;

- (id)performSelector:(SEL)aSelector withObjects:(NSArray *)objects;
- (id)performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2 withObject:(id)object3;

- (id)forwardSelector:(SEL)aSelector withObjects:(NSArray *)objects nextTarget:(id(^)(id target, BOOL responds, id returnValue))block;
- (id)forwardSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2 withObject:(id)object3 nextTarget:(id(^)(id target, BOOL responds, id returnValue))block;
- (id)forwardSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2 nextTarget:(id(^)(id target, BOOL responds, id returnValue))block;
- (id)forwardSelector:(SEL)aSelector withObject:(id)object1 nextTarget:(id(^)(id target, BOOL responds, id returnValue))block;
- (id)forwardSelector:(SEL)aSelector nextTarget:(id(^)(id target, BOOL responds, id returnValue))block;

- (BOOL)isEqualToAnyObject:(NSArray *)objects;

- (BOOL)isKindOfAnyClass:(NSArray<Class> *)classes;
- (BOOL)isMemberOfAnyClass:(NSArray<Class> *)classes;

@property (assign, nonatomic, readonly) BOOL isNull;

- (NSData *)archivedData;
+ (instancetype)createFromArchivedData:(NSData *)data;

- (id)tryGetValueForKey:(NSString *)key;
- (BOOL)trySetValue:(id)value forKey:(NSString *)key;

@end

@interface NSNumber (Convenience)

@property (assign, nonatomic, readonly) BOOL isNotANumber;
@property (strong, nonatomic, readonly) NSDecimalNumber *decimalNumber;

@end

@interface NSMethodSignature (Convenience)

- (BOOL)methodReturnTypeIs:(char *)methodReturnType;

@end

@interface NSInvocation (Convenience)

- (id)getReturnValue;

@end
