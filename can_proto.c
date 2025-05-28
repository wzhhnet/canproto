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

#define RET_VOID
#define RETURN_IF_NULL(PTR, RET)                                               \
    do {                                                                       \
        if ((PTR) == NULL) return RET;                                         \
    } while (0)

#define RETURN_IF_TRUE(EXPR, RET)                                              \
    do {                                                                       \
        if (EXPR) return RET;                                                  \
    } while (0)

#define RETURN_IF_FAIL(RET)                                                    \
    do {                                                                       \
        if (RET) return RET;                                                   \
    } while (0)

#define DIFF_BYTES(FMT)                                                        \
    (kCanEndian == CAN_BIG_ENDIAN ? ((FMT)->start_byte - (FMT)->end_byte)      \
                                  : ((FMT)->end_byte - (FMT)->start_byte))

#define MOVE_BYTES(FMT, BYTE_PTR)                                              \
    do {                                                                       \
        if (kCanEndian == CAN_LITTLE_ENDIAN)                                   \
            ++(BYTE_PTR);                                                      \
        else                                                                   \
            --(BYTE_PTR);                                                      \
    } while (0)

#define CHECK_FORMAT_BYTES(FMT)                                                \
    do {                                                                       \
        RETURN_IF_TRUE((FMT)->start_byte >= CAN_MSG_LEN, RC_ERR_FMT_S_BYTE);   \
        RETURN_IF_TRUE((FMT)->end_byte >= CAN_MSG_LEN, RC_ERR_FMT_E_BYTE);     \
        if (kCanEndian == CAN_BIG_ENDIAN) {                                    \
            RETURN_IF_TRUE((FMT)->start_byte < (FMT)->end_byte,                \
                           RC_ERR_FMT_BYTE_SEQ);                               \
        } else {                                                               \
            RETURN_IF_TRUE((FMT)->start_byte > (FMT)->end_byte,                \
                           RC_ERR_FMT_BYTE_SEQ);                               \
        }                                                                      \
    } while (0)

#define CHECK_FORMAT_BITS(FMT)                                                 \
    do {                                                                       \
        RETURN_IF_TRUE((FMT)->start_bit > 7, RC_ERR_FMT_S_BIT);                \
        RETURN_IF_TRUE((FMT)->end_bit > 7, RC_ERR_FMT_E_BIT);                  \
        RETURN_IF_TRUE((FMT)->bits == 0 || (FMT)->bits > 32, RC_ERR_FMT_BITS); \
        uint8_t bytes = DIFF_BYTES(FMT);                                       \
        uint8_t bits = (bytes * 8u) - (FMT)->start_bit + (FMT)->end_bit + 1u;  \
        RETURN_IF_TRUE((FMT)->bits != bits, RC_ERR_FMT_BITS_CALC);             \
    } while (0)

#define CHECK_FORMAT(FMT)                                                      \
    do {                                                                       \
        CHECK_FORMAT_BYTES(FMT);                                               \
        CHECK_FORMAT_BITS(FMT);                                                \
    } while (0)

static uint8_t kCanEndian = CAN_BIG_ENDIAN; // default to big-endian

static int check_format(const struct can_format_t *fmt)
{
    CHECK_FORMAT(fmt);
    return RC_SUCCESS;
}

void set_can_endian(uint8_t endian)
{
    if (endian == CAN_BIG_ENDIAN || endian == CAN_LITTLE_ENDIAN) {
        kCanEndian = endian;
    }
}

int encode_can_data(const struct can_format_t *fmt, struct can_frame_t *frame,
                    uint32_t v)
{
    RETURN_IF_NULL(fmt, RC_ERR_NULL_PTR);
    RETURN_IF_NULL(frame, RC_ERR_NULL_PTR);
    RETURN_IF_FAIL(check_format(fmt));

    uint8_t bits = fmt->bits;
    uint8_t *byte = frame->bytes + fmt->start_byte;
    uint8_t s_bit = fmt->start_bit;
    while (bits) {
        uint8_t mask_len = 8u - s_bit;
        if (mask_len > bits) mask_len = bits;
        uint8_t mask = ((1u << mask_len) - 1u) << s_bit;
        *byte = (*byte & ~mask) | (uint8_t)((v << s_bit) & mask);
        bits -= mask_len;
        v >>= mask_len;
        s_bit = 0;             // subsequent bytes start from bit 0
        MOVE_BYTES(fmt, byte); // move to the next byte
    }
    return RC_SUCCESS;
}

int decode_can_data(const struct can_format_t *fmt,
                    const struct can_frame_t *frame, uint32_t *v)
{
    RETURN_IF_NULL(fmt, RC_ERR_NULL_PTR);
    RETURN_IF_NULL(frame, RC_ERR_NULL_PTR);
    RETURN_IF_NULL(v, RC_ERR_NULL_PTR);
    RETURN_IF_FAIL(check_format(fmt));

    uint8_t bits = 0;
    uint8_t *byte = (uint8_t *)(frame->bytes) + fmt->start_byte;
    uint8_t s_bit = fmt->start_bit;
    *v = 0;
    while (bits < fmt->bits) {
        uint8_t mask_len = 8u - s_bit;
        if (mask_len > (fmt->bits - bits)) mask_len = fmt->bits - bits;
        uint8_t mask = ((1u << mask_len) - 1u) << s_bit;   // create mask
        *v |= ((uint32_t)(*byte & mask) >> s_bit) << bits; // extract value
        bits += mask_len;
        s_bit = 0;             // subsequent bytes start from bit 0
        MOVE_BYTES(fmt, byte); // move to the next byte
    }
    return RC_SUCCESS;
}
