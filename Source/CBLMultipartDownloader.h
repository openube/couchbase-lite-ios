//
//  CBLMultipartDownloader.h
//  CouchbaseLite
//
//  Created by Jens Alfke on 1/31/12.
//  Copyright (c) 2012 Couchbase, Inc. All rights reserved.
//

#import "CBLRemoteRequest.h"
@class CBLMultipartDocumentReader, CBLDatabase;


/** Downloads a remote CouchDB document in multipart format.
    Attachments are added to the database, but the document body isn't. */
@interface CBLMultipartDownloader : CBLRemoteRequest
{
    @private
    CBLMultipartDocumentReader* _reader;
}

- (instancetype) initWithURL: (NSURL*)url
                    database: (CBLDatabase*)database
              requestHeaders: (NSDictionary *) requestHeaders
                onCompletion: (CBLRemoteRequestCompletionBlock)onCompletion;

@property (readonly) NSDictionary* document;

@end
