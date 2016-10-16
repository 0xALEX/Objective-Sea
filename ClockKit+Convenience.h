//
//  ClockKit+Convenience.h
//  Sleep Diary
//
//  Created by Alexander Ivanov on 12.10.16.
//  Copyright © 2016 Alexander Ivanov. All rights reserved.
//

#import <ClockKit/ClockKit.h>

#import "NSHelper.h"

typedef enum : NSUInteger {
	CLKComplicationFamilyMemberRingImage,
	CLKComplicationFamilyMemberRingText,
	CLKComplicationFamilyMemberSimpleImage,
	CLKComplicationFamilyMemberSimpleText,
	CLKComplicationFamilyMemberStackImage,
	CLKComplicationFamilyMemberStackText,
} CLKComplicationFamilyMember;

@interface CLKComplicationTemplate (Convenience)

- (void)setText:(CLKTextProvider *)value;
- (void)setRing:(CLKComplicationRingStyle)value;
- (void)setFill:(float)value;
- (void)setImage:(CLKImageProvider *)value;

- (void)setText:(NSString *)value shortText:(NSString *)text;
- (void)setImage:(UIImage *)value tintColor:(UIColor *)color;

+ (CLKComplicationTemplate *)createWithFamily:(CLKComplicationFamily)family member:(CLKComplicationFamilyMember)member;

@end

@interface CLKComplicationServer (Convenience)

- (void)extendTimeline:(CLKComplication *)complication;
- (void)reloadTimeline:(CLKComplication *)complication;

@end
