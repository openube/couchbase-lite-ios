//
//  CBLStatus.h
//  CouchbaseLite
//
//  Created by Jens Alfke on 4/5/12.
//  Copyright (c) 2012 Couchbase, Inc. All rights reserved.
//


/** CouchbaseLite internal status/error codes. Superset of HTTP status codes. */
typedef enum {
    kCBLStatusOK             = 200,
    kCBLStatusCreated        = 201,
    kCBLStatusAccepted       = 206,
    
    kCBLStatusNotModified    = 304,
    
    kCBLStatusBadRequest     = 400,
    kCBLStatusUnauthorized   = 401,
    kCBLStatusForbidden      = 403,
    kCBLStatusNotFound       = 404,
    kCBLStatusNotAcceptable  = 406,
    kCBLStatusConflict       = 409,
    kCBLStatusDuplicate      = 412,      // Formally known as "Precondition Failed"
    kCBLStatusUnsupportedType= 415,
    
    kCBLStatusServerError    = 500,
    
    // Non-HTTP errors:
    kCBLStatusBadEncoding    = 490,
    kCBLStatusBadAttachment  = 491,
    kCBLStatusAttachmentNotFound = 492,
    kCBLStatusBadJSON        = 493,
    kCBLStatusBadID          = 494,
    kCBLStatusBadParam       = 495,
    kCBLStatusDeleted        = 496,      // Document deleted
    
    kCBLStatusUpstreamError  = 589,      // Error from remote replication server
    kCBLStatusDBError        = 590,      // SQLite error
    kCBLStatusCorruptError   = 591,      // bad data in database
    kCBLStatusAttachmentError= 592,      // problem with attachment store
    kCBLStatusCallbackError  = 593,      // app callback (emit fn, etc.) failed
    kCBLStatusException      = 594,      // Exception raised/caught
} CBLStatus;


static inline bool CBLStatusIsError(CBLStatus status) {return status >= 400;}

int CBLStatusToHTTPStatus( CBLStatus status, NSString** outMessage );

NSError* CBLStatusToNSError( CBLStatus status, NSURL* url );
CBLStatus CBLStatusFromNSError(NSError* error, CBLStatus defaultStatus);