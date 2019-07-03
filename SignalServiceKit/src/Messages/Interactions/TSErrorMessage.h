//
//  Copyright (c) 2019 Open Whisper Systems. All rights reserved.
//

#import "OWSReadTracking.h"
#import "TSMessage.h"

NS_ASSUME_NONNULL_BEGIN

@class SSKProtoEnvelope;
@class SignalServiceAddress;

typedef NS_ENUM(int32_t, TSErrorMessageType) {
    TSErrorMessageNoSession,
    // DEPRECATED: We no longer create TSErrorMessageWrongTrustedIdentityKey, but
    // persisted legacy messages could exist indefinitly.
    TSErrorMessageWrongTrustedIdentityKey,
    TSErrorMessageInvalidKeyException,
    // unused
    TSErrorMessageMissingKeyId,
    TSErrorMessageInvalidMessage,
    // unused
    TSErrorMessageDuplicateMessage,
    TSErrorMessageInvalidVersion,
    TSErrorMessageNonBlockingIdentityChange,
    TSErrorMessageUnknownContactBlockOffer,
    TSErrorMessageGroupCreationFailed,
};

@interface TSErrorMessage : TSMessage <OWSReadTracking>

- (instancetype)initMessageWithTimestamp:(uint64_t)timestamp
                                inThread:(nullable TSThread *)thread
                             messageBody:(nullable NSString *)body
                           attachmentIds:(NSArray<NSString *> *)attachmentIds
                        expiresInSeconds:(uint32_t)expiresInSeconds
                         expireStartedAt:(uint64_t)expireStartedAt
                           quotedMessage:(nullable TSQuotedMessage *)quotedMessage
                            contactShare:(nullable OWSContact *)contact
                             linkPreview:(nullable OWSLinkPreview *)linkPreview
                          messageSticker:(nullable MessageSticker *)messageSticker NS_UNAVAILABLE;

- (instancetype)initWithTimestamp:(uint64_t)timestamp
                         inThread:(nullable TSThread *)thread
                      messageBody:(nullable NSString *)body
                    attachmentIds:(NSArray<NSString *> *)attachmentIds
                 expiresInSeconds:(uint32_t)expiresInSeconds
                  expireStartedAt:(uint64_t)expireStartedAt NS_UNAVAILABLE;

- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithTimestamp:(uint64_t)timestamp
                         inThread:(nullable TSThread *)thread
                failedMessageType:(TSErrorMessageType)errorMessageType
                          address:(nullable SignalServiceAddress *)address NS_DESIGNATED_INITIALIZER;

// --- CODE GENERATION MARKER

// This snippet is generated by /Scripts/sds_codegen/sds_generate.py. Do not manually edit it, instead run `sds_codegen.sh`.

// clang-format off

- (instancetype)initWithUniqueId:(NSString *)uniqueId
             receivedAtTimestamp:(uint64_t)receivedAtTimestamp
                          sortId:(uint64_t)sortId
                       timestamp:(uint64_t)timestamp
                  uniqueThreadId:(NSString *)uniqueThreadId
                   attachmentIds:(NSArray<NSString *> *)attachmentIds
                            body:(nullable NSString *)body
                    contactShare:(nullable OWSContact *)contactShare
                 expireStartedAt:(uint64_t)expireStartedAt
                       expiresAt:(uint64_t)expiresAt
                expiresInSeconds:(unsigned int)expiresInSeconds
                     linkPreview:(nullable OWSLinkPreview *)linkPreview
                  messageSticker:(nullable MessageSticker *)messageSticker
perMessageExpirationDurationSeconds:(unsigned int)perMessageExpirationDurationSeconds
  perMessageExpirationHasExpired:(BOOL)perMessageExpirationHasExpired
       perMessageExpireStartedAt:(uint64_t)perMessageExpireStartedAt
                   quotedMessage:(nullable TSQuotedMessage *)quotedMessage
                   schemaVersion:(NSUInteger)schemaVersion
       errorMessageSchemaVersion:(NSUInteger)errorMessageSchemaVersion
                       errorType:(TSErrorMessageType)errorType
                            read:(BOOL)read
                recipientAddress:(nullable SignalServiceAddress *)recipientAddress
NS_SWIFT_NAME(init(uniqueId:receivedAtTimestamp:sortId:timestamp:uniqueThreadId:attachmentIds:body:contactShare:expireStartedAt:expiresAt:expiresInSeconds:linkPreview:messageSticker:perMessageExpirationDurationSeconds:perMessageExpirationHasExpired:perMessageExpireStartedAt:quotedMessage:schemaVersion:errorMessageSchemaVersion:errorType:read:recipientAddress:));

// clang-format on

// --- CODE GENERATION MARKER

+ (instancetype)corruptedMessageWithEnvelope:(SSKProtoEnvelope *)envelope
                             withTransaction:(YapDatabaseReadWriteTransaction *)transaction;

+ (instancetype)corruptedMessageInUnknownThread;

+ (instancetype)invalidVersionWithEnvelope:(SSKProtoEnvelope *)envelope
                           withTransaction:(YapDatabaseReadWriteTransaction *)transaction;

+ (instancetype)invalidKeyExceptionWithEnvelope:(SSKProtoEnvelope *)envelope
                                withTransaction:(YapDatabaseReadWriteTransaction *)transaction;

+ (instancetype)missingSessionWithEnvelope:(SSKProtoEnvelope *)envelope
                           withTransaction:(YapDatabaseReadWriteTransaction *)transaction;

+ (instancetype)nonblockingIdentityChangeInThread:(TSThread *)thread address:(SignalServiceAddress *)address;

@property (nonatomic, readonly) TSErrorMessageType errorType;
@property (nullable, nonatomic, readonly) SignalServiceAddress *recipientAddress;

@end

NS_ASSUME_NONNULL_END
