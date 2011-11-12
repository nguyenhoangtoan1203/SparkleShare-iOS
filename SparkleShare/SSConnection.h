//
//  SSConnection.h
//  SparkleShare
//
//  Created by Sergey Klimov on 07.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@class SSConnection;

@protocol SSConnectionDelegate <NSObject>
-(void) connectionEstablishingSuccess:(SSConnection*) connection;
-(void) connectionEstablishingFailed:(SSConnection*) connection;
@end

@protocol SSConnectionFoldersDelegate <NSObject>
-(void) connection:(SSConnection*) connection foldersLoaded:(NSArray*) folders;
-(void) connectionFoldersLoadingFailed:(SSConnection*) connection;
@end

@interface SSConnection : NSObject
{
@private
    NSURL* address;
    NSString* identCode;
    NSString* authCode;
    NSArray* folders;
    NSOperationQueue *queue;
    id<SSConnectionDelegate> delegate;
    id<SSConnectionFoldersDelegate> foldersDelegate;

}

@property (strong) id<SSConnectionDelegate> delegate;
@property (strong) id<SSConnectionFoldersDelegate> foldersDelegate;
@property (retain) NSArray* folders;

-(id) initWithAddress:(NSURL*)anAddress identCode:(NSString*)anIdentCode authCode:(NSString*)anAuthCode;
-(id) initWithUserDefaults;
-(NSData*) getDataWithRequest:(NSString*)request;
-(id*) getObjectWithRequest:(NSString*)request;
-(void) linkDeviceWithAddress:(NSURL*)anAddress code:(NSString*)aCode;
-(void) loadFolders;
@end
