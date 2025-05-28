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

#ifndef __INCLUDE_CAN_PROTOCOL_H__
#define __INCLUDE_CAN_PROTOCOL_H__

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CAN_MSG_LEN 8
#define CAN_BIG_ENDIAN 0
#define CAN_LITTLE_ENDIAN 1

enum result_code_t {
    RC_SUCCESS = 0,
    RC_ERR_NULL_PTR,
    RC_ERR_FMT_BITS,
    RC_ERR_FMT_S_BIT,
    RC_ERR_FMT_E_BIT,
    RC_ERR_FMT_S_BYTE,
    RC_ERR_FMT_E_BYTE,
    RC_ERR_FMT_BYTE_SEQ,
    RC_ERR_FMT_BITS_CALC,
};

struct can_format_t {
    uint8_t field_id;
    uint8_t frame_id;
    uint8_t bits;
    uint8_t end_byte;
    uint8_t end_bit;
    uint8_t start_byte;
    uint8_t start_bit;
};

struct can_frame_t {
    uint8_t bytes[CAN_MSG_LEN]; // CAN frame data
};

/// @brief set the CAN protocol endianness
/// @param endian CAN_BIG_ENDIAN or CAN_LITTLE_ENDIAN
void set_can_endian(uint8_t endian);

/// @brief encodes data into a CAN frame based on the specified format
/// @param fmt the format of the CAN frame
/// @param frame the CAN frame to encode data into
/// @param v the value to encode
/// @return RC_SUCCESS on success, or an error code on failure
int encode_can_data(const struct can_format_t *fmt, struct can_frame_t *frame,
                    uint32_t v);

/// @brief decodes data from a CAN frame based on the specified format
/// @param fmt the format of the CAN frame
/// @param frame the CAN frame to decode data from
/// @param v pointer to store the decoded value
/// @return RC_SUCCESS on success, or an error code on failure
int decode_can_data(const struct can_format_t *fmt,
                    const struct can_frame_t *frame, uint32_t *v);

#ifdef __cplusplus
}
#endif

#endif /* __INCLUDE_CAN_PROTOCOL_H__ */
