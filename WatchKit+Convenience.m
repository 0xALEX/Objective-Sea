//
//  WatchKit+Convenience.m
//  Sleep Diary
//
//  Created by Alexander Ivanov on 14.10.16.
//  Copyright © 2016 Alexander Ivanov. All rights reserved.
//

#import "WatchKit+Convenience.h"

@implementation WKInterfaceTable (Convenience)

- (void)setRows:(NSDictionary<NSString *, NSNumber *> *)dictionary {
	NSMutableArray *array = [NSMutableArray array];

	for (NSString *key in dictionary) {
		NSUInteger count = dictionary[key].unsignedIntegerValue;

		for (NSUInteger index = 0; index < count; index++)
			[array addObject:key];
	}

	[self setRowTypes:array];
}

@end

@implementation WKInterfaceTimer (Convenience)

- (void)setInterval:(NSTimeInterval)interval {
	NSDate *date = [[NSDate date] dateByAddingTimeInterval:0.0 - interval];

	[self setDate:date];
}

@end

@implementation WKPickerItem (Convenience)

- (instancetype)initWithTitle:(NSString *)title caption:(NSString *)caption accessoryImage:(WKImage *)accessoryImage contentImage:(WKImage *)contentImage {
	self = [self init];

	if (self) {
		self.title = title;
		self.caption = caption;
		self.accessoryImage = accessoryImage;
		self.contentImage = contentImage;
	}

	return self;
}

@end

@implementation WKInterfacePicker (Convenience)

- (void)setItemsWithTitles:(NSArray<NSString *> *)titles {
	NSMutableArray<WKPickerItem *> *items = [NSMutableArray arrayWithCapacity:titles.count];
	for (NSString *title in titles)
		[items addObject:[[WKPickerItem alloc] initWithTitle:title caption:Nil accessoryImage:Nil contentImage:Nil]];

	[self setItems:items];
}

@end
