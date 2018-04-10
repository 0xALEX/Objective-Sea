//
//  Vision+Convenience.h
//  Scans
//
//  Created by Alexander Ivanov on 26.02.2018.
//  Copyright © 2018 Alexander Ivanov. All rights reserved.
//

#import <Vision/Vision.h>
#import <UIKit/UIKit.h>

#import "CoreGraphics+Convenience.h"
#import "CoreImage+Convenience.h"

#import "NSObject+Convenience.h"

@interface VNImageRequestHandler (Convenience)

- (BOOL)performRequests:(NSArray<VNRequest *> *)requests;

@end

@interface VNSequenceRequestHandler (Convenience)

- (BOOL)performRequests:(NSArray<VNRequest *> *)requests onCVPixelBuffer:(CVPixelBufferRef)pixelBuffer;
- (BOOL)performRequests:(NSArray<VNRequest *> *)requests onCVPixelBuffer:(CVPixelBufferRef)pixelBuffer orientation:(CGImagePropertyOrientation)orientation;

- (BOOL)performRequests:(NSArray<VNRequest *> *)requests onCGImage:(CGImageRef)image;
- (BOOL)performRequests:(NSArray<VNRequest *> *)requests onCGImage:(CGImageRef)image orientation:(CGImagePropertyOrientation)orientation;

- (BOOL)performRequests:(NSArray<VNRequest *> *)requests onCIImage:(CIImage*)image;
- (BOOL)performRequests:(NSArray<VNRequest *> *)requests onCIImage:(CIImage*)image orientation:(CGImagePropertyOrientation)orientation;

- (BOOL)performRequests:(NSArray<VNRequest *> *)requests onImageURL:(NSURL*)imageURL;
- (BOOL)performRequests:(NSArray<VNRequest *> *)requests onImageURL:(NSURL*)imageURL orientation:(CGImagePropertyOrientation)orientation;

- (BOOL)performRequests:(NSArray<VNRequest *> *)requests onImageData:(NSData*)imageData;
- (BOOL)performRequests:(NSArray<VNRequest *> *)requests onImageData:(NSData*)imageData orientation:(CGImagePropertyOrientation)orientation;

@end

@interface VNRequest (Convenience)

+ (instancetype)requestWithCompletionHandler:(void(^)(NSArray *results))completionHandler;

@end

@interface VNDetectedObjectObservation (Convenience)

@property (assign, nonatomic, readonly) CGRect bounds;

@end

#define VNImageOptionPreferBackgroundProcessing @"VNImageOptionPreferBackgroundProcessing"
#define VNImageOptionReportCharacterBoxes @"VNImageOptionReportCharacterBoxes"

@interface UIImage (Vision)

- (BOOL)detectTextRectanglesWithOptions:(NSDictionary<VNImageOption, id> *)options completionHandler:(void(^)(NSArray<VNTextObservation *> *results))completionHandler;
- (BOOL)detectRectanglesWithOptions:(NSDictionary<VNImageOption, id> *)options completionHandler:(void(^)(NSArray<VNRectangleObservation *> *results))completionHandler;

- (CGRect)boundsForObservation:(VNDetectedObjectObservation *)observation;

- (UIImage *)imageWithObservation:(VNDetectedObjectObservation *)observation;

- (UIImage *)imageWithRectangle:(VNRectangleObservation *)rectangle;

@end
