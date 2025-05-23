/*
 * Can Protocol
 *
 * Author wanch
 * Date 2019/10/10
 * Email wzhhnet@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "can_proto.h"

static void encode_simple_byte(const struct can_format_t *fmt,
                               struct can_frame_t *frame, uint32_t v)
{
    uint8_t mask = ((1u << fmt->bits) - 1u) << fmt->start_bit;
    uint8_t *byte = frame->bytes + fmt->start_byte;
    *byte = (*byte & ~mask) | (uint8_t)(v << fmt->start_bit);
}

static uint32_t decode_simple_byte(const struct can_format_t *fmt,
                                   const struct can_frame_t *frame)
{
    uint8_t mask = ((1u << fmt->bits) - 1u) << fmt->start_bit;
    uint8_t *byte = (uint8_t *)(frame->bytes) + fmt->start_byte;
    return (*byte & mask) >> fmt->start_bit;
}

static void encode_multi_bytes(const struct can_format_t *fmt,
                               struct can_frame_t *frame, uint32_t v)
{
    uint8_t bits = fmt->bits;
    uint8_t diff_bytes = fmt->start_byte - fmt->end_byte;
    /*! encode lsb */
    uint8_t *byte = frame->bytes + fmt->start_byte;
    uint8_t mask = ((1u << (8u - fmt->start_bit)) - 1u) << fmt->start_bit;

    *byte = (*byte & ~mask) | (uint8_t)(v << fmt->start_bit);
    bits = bits - (8u - fmt->start_bit);
    /*! encode msb */
    while (--diff_bytes) {
        --byte;
        *byte = v >> (fmt->bits - bits);
        bits -= 8u;
    }

    if (bits) {
        --byte;
        mask = (1u << bits) - 1u;
        *byte = (*byte & ~mask) | (uint8_t)(v >> (fmt->bits - bits));
    }
}

static uint32_t decode_multi_bytes(const struct can_format_t *fmt,
                                   const struct can_frame_t *frame)
{
    uint8_t bits = 8u - fmt->start_bit;
    uint8_t diff_bytes = fmt->start_byte - fmt->end_byte;

    /*! decode lsb */
    uint8_t *byte = (uint8_t *)(frame->bytes) + fmt->start_byte;
    uint8_t mask = ((1u << bits) - 1u) << fmt->start_bit;
    uint32_t ret = (*byte & mask) >> fmt->start_bit;

    /*! decode msb */
    while (--diff_bytes) {
        --byte;
        ret |= ((uint32_t)*byte) << bits;
        bits += 8u;
    }

    if (bits < fmt->bits) {
        --byte;
        mask = (1u << (fmt->end_bit + 1u)) - 1u;
        ret |= (uint32_t)(*byte & mask) << bits;
    }

    return ret;
}

void encode_can_data(const struct can_format_t *fmt, struct can_frame_t *frame,
                     uint32_t v)
{
    uint8_t diff_bytes = fmt->start_byte - fmt->end_byte;
    if (diff_bytes == 0) {
        encode_simple_byte(fmt, frame, v);
    } else {
        encode_multi_bytes(fmt, frame, v);
    }
}

uint32_t decode_can_data(const struct can_format_t *fmt,
                         const struct can_frame_t *frame)
{
    uint32_t ret = 0;
    uint8_t diff_bytes = fmt->start_byte - fmt->end_byte;
    if (diff_bytes == 0) {
        ret = decode_simple_byte(fmt, frame);
    } else {
        ret = decode_multi_bytes(fmt, frame);
    }

    return ret;
}
