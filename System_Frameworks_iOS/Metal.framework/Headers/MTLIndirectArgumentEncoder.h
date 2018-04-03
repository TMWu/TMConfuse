//
//  MTLIndirectArgumentEncoder.h
//  Metal
//
//  Copyright (c) 2016 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Metal/MTLDefines.h>

NS_ASSUME_NONNULL_BEGIN
@protocol MTLDevice;
@protocol MTLBuffer;
@protocol MTLTexture;
@protocol MTLSamplerState;
@protocol MTLRenderPipelineState;

/*!
 * @protocol MTLIndirectArgumentEncoder
 * @discussion MTLIndirectArgumentEncoder is deprecated, use MTLArgumentEncoder instead
 */
NS_AVAILABLE(10_13, 11_0)
@protocol MTLIndirectArgumentEncoder <NSObject>

/*!
 @property device
 @abstract The device this indirect argument encoder was created against.
 */
@property (readonly) id <MTLDevice> device;

/*!
 @property label
 @abstract A string to help identify this object.
 */
@property (nullable, copy, atomic) NSString *label;

/*!
 * @property encodedLength
 * @abstract The number of bytes required to store the encoded resource bindings.
 */
@property (readonly) NSUInteger encodedLength;

/*!
 * @property alignment
 * @abstract The alignment in bytes required to store the encoded resource bindings.
 */
@property (readonly) NSUInteger alignment;

/*!
 * @method setIndirectArgumentBuffer:offset:
 * @brief Sets the destination buffer and offset indirect arguments will be encoded into.
 */
- (void)setIndirectArgumentBuffer:(id <MTLBuffer>)indirectArgumentBuffer offset:(NSUInteger)offset;

/*!
 * @method setIndirectArgumentBuffer:offset:arrayElement:
 * @brief Sets the destination buffer, starting offset and specific array element indirect arguments will be encoded into. arrayElement represents
          the desired element of IAB array targetted by encoding
 */
- (void)setIndirectArgumentBuffer:(id <MTLBuffer>)indirectArgumentBuffer startOffset:(NSUInteger)startOffset arrayElement:(NSUInteger)arrayElement;

/*!
 * @method setBuffer:offset:atIndex:
 * @brief Set a buffer at the given bind point index.
 */
- (void)setBuffer:(id <MTLBuffer>)buffer offset:(NSUInteger)offset atIndex:(NSUInteger)index;

/*!
 * @method setBuffers:offsets:withRange:
 * @brief Set an array of buffers at the given bind point index range.
 */
- (void)setBuffers:(const id <MTLBuffer> __nullable [__nonnull])buffers offsets:(const NSUInteger [__nonnull])offsets withRange:(NSRange)range;

/*!
 * @method setTexture:atIndex:
 * @brief Set a texture at the given bind point index.
 */
- (void)setTexture:(id <MTLTexture>)texture atIndex:(NSUInteger)index;

/*!
 * @method setTextures:withRange:
 * @brief Set an array of textures at the given bind point index range.
 */
- (void)setTextures:(const id <MTLTexture> __nullable [__nonnull])textures withRange:(NSRange)range;

/*!
 * @method setSamplerState:atIndex:
 * @brief Set a sampler at the given bind point index.
 */
- (void)setSamplerState:(id <MTLSamplerState>)sampler atIndex:(NSUInteger)index;

/*!
 * @method setSamplerStates:withRange:
 * @brief Set an array of samplers at the given bind point index range.
 */
- (void)setSamplerStates:(const id <MTLSamplerState> __nullable [__nonnull])samplers withRange:(NSRange)range;

/*!
 * @method constantDataAtIndex:
 * @brief Returns a pointer to the constant data at the given bind point index.
 */
- (void*)constantDataAtIndex:(NSUInteger)index;



@end

NS_ASSUME_NONNULL_END
