//
//  MapKit+Convenience.h
//  Crowd Guard
//
//  Created by Alexander Ivanov on 17.11.16.
//  Copyright © 2016 Alexander Ivanov. All rights reserved.
//

#import <MapKit/MapKit.h>

@interface MKMapView (Convenience)

- (void)setRegionDistance:(double)regionDistance animated:(BOOL)animated;
- (void)setRegionDistance:(double)regionDistance;

- (void)removeAllAnnotations;
- (void)removeAllOverlays;

- (void)removeAllAnnotationsAndOverlays;

- (MKAnnotationView *)viewForNullableAnnotation:(id<MKAnnotation>)annotation;

@end

@interface MKDistanceFormatter (Convenience)

+ (instancetype)defaultFormatter;

@end

@interface MKShape (Convenience)

- (instancetype)initWithTitle:(NSString *)title subtitle:(NSString *)subtitle;

@end

@interface MKPointAnnotation (Convenience)

- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate title:(NSString *)title subtitle:(NSString *)subtitle;

@end

@interface MKDirectionsRequest (Convenience)

- (instancetype)initWithSource:(MKMapItem *)source destination:(MKMapItem *)destination transportType:(MKDirectionsTransportType)transportType requestsAlternateRoutes:(BOOL)requestsAlternateRoutes;
- (instancetype)initWithSourcePlacemark:(MKPlacemark *)source destinationPlacemark:(MKPlacemark *)destination transportType:(MKDirectionsTransportType)transportType requestsAlternateRoutes:(BOOL)requestsAlternateRoutes;
- (instancetype)initWithSourceCoordinate:(CLLocationCoordinate2D)source destinationCoordinate:(CLLocationCoordinate2D)destination transportType:(MKDirectionsTransportType)transportType requestsAlternateRoutes:(BOOL)requestsAlternateRoutes;

- (MKDirections *)calculateDirectionsWithCompletionHandler:(MKDirectionsHandler)completionHandler;
- (MKDirections *)calculateETAWithCompletionHandler:(MKETAHandler)completionHandler;

@end
