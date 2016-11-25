//
//  NSFormatter+Convenience.m
//  Sleep Diary
//
//  Created by Alexander Ivanov on 16.10.16.
//  Copyright © 2016 Alexander Ivanov. All rights reserved.
//

#import "NSFormatter+Convenience.h"

@implementation NSDateFormatter (Convenience)

__static(NSDateFormatter *, defaultFormatter, ({
	NSDateFormatter *formatter = [NSDateFormatter new];
	formatter.dateStyle = NSDateFormatterShortStyle;
	formatter.timeStyle = NSDateFormatterMediumStyle;
	formatter;
}))

__static(NSDateFormatter *, RFC3339Formatter, ({
	NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
	[formatter setLocale:[[NSLocale alloc] initWithLocaleIdentifier:@"en_US_POSIX"]];
	[formatter setDateFormat:@"yyyy'-'MM'-'dd'T'HH':'mm':'ss'Z'"];
	[formatter setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
	formatter;
}))

- (NSDate *)dateFromValue:(NSString *)string {
	return string ? [self dateFromString:string] : Nil;
}

- (NSString *)stringFromValue:(NSDate *)date {
	return date ? [self stringFromDate:date] : Nil;
}

- (NSString *)weekdaySymbol:(NSUInteger)weekday {
	return weekday > self.standaloneWeekdaySymbols.count ? Nil : self.standaloneWeekdaySymbols[weekday - 1];
}

- (NSString *)monthSymbol:(NSUInteger)month {
	return month > self.standaloneMonthSymbols.count ? Nil : self.standaloneMonthSymbols[month - 1];
}

- (NSString *)weekdaySymbolForDate:(NSDate *)date {
	return [self weekdaySymbol:[[NSCalendar currentCalendar] component:NSCalendarUnitWeekday fromDate:date]];
}

- (NSString *)monthSymbolForDate:(NSDate *)date {
	return [self monthSymbol:[[NSCalendar currentCalendar] component:NSCalendarUnitMonth fromDate:date]];
}

@end

@implementation NSDateComponentsFormatter (Convenience)

+ (instancetype)dateComponentsFormatterWithAllowedUnits:(NSCalendarUnit)allowedUnits unitsStyle:(NSDateComponentsFormatterUnitsStyle)unitsStyle {
	NSDateComponentsFormatter *instance = [NSDateComponentsFormatter new];
	instance.allowedUnits = allowedUnits;
	instance.unitsStyle = unitsStyle;
	instance.zeroFormattingBehavior = NSDateComponentsFormatterZeroFormattingBehaviorPad;
	return instance;
}

+ (instancetype)dateComponentsFormatterWithAllowedUnits:(NSCalendarUnit)allowedUnits {
	return [self dateComponentsFormatterWithAllowedUnits:allowedUnits unitsStyle:NSDateComponentsFormatterUnitsStylePositional];
}

__static(NSDateComponentsFormatter *, hhmmFormatter, [self dateComponentsFormatterWithAllowedUnits:NSCalendarUnitHour | NSCalendarUnitMinute])
__static(NSDateComponentsFormatter *, hhmmssFormatter, [self dateComponentsFormatterWithAllowedUnits:NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitSecond])
__static(NSDateComponentsFormatter *, mmssFormatter, [self dateComponentsFormatterWithAllowedUnits:NSCalendarUnitMinute | NSCalendarUnitSecond])

__static(NSDateComponentsFormatter *, mmssAbbreviatedFormatter, [NSDateComponentsFormatter dateComponentsFormatterWithAllowedUnits:NSCalendarUnitMinute | NSCalendarUnitSecond unitsStyle:NSDateComponentsFormatterUnitsStyleAbbreviated])
__static(NSDateComponentsFormatter *, mmShortFormatter, [NSDateComponentsFormatter dateComponentsFormatterWithAllowedUnits:NSCalendarUnitMinute unitsStyle:NSDateComponentsFormatterUnitsStyleShort])

- (NSString *)stringFromValue:(NSDate *)startDate toValue:(NSDate *)endDate {
	return startDate && endDate ? [self stringFromDate:startDate toDate:endDate] : Nil;
}

@end

@implementation NSDateIntervalFormatter (Convinience)

- (instancetype)initWithDateStyle:(NSDateIntervalFormatterStyle)dateStyle timeStyle:(NSDateIntervalFormatterStyle)timeStyle {
	self = [self init];

	if (self) {
		self.dateStyle = dateStyle;
		self.timeStyle = timeStyle;
	}

	return self;
}

- (NSString *)stringFromTimeInterval:(NSTimeInterval)fromTimeInterval toTimeInterval:(NSTimeInterval)toTimeInterval {
	NSDate *fromDate = [NSDate dateWithTimeIntervalSinceReferenceDate:fromTimeInterval];
	NSDate *toDate = [NSDate dateWithTimeIntervalSinceReferenceDate:toTimeInterval];
	return [self stringFromDate:fromDate toDate:toDate];
}

@end