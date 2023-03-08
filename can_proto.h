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

#ifdef __cplusplus
extern "C" {
#endif

#define CAN_MSG_LEN 8

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
    uint8_t bytes[CAN_MSG_LEN];
};

void encode_can_data(const struct can_format_t *fmt, struct can_frame_t *frame,
                     uint32_t v);
uint32_t decode_can_data(const struct can_format_t *fmt,
                         const struct can_frame_t *frame);

#ifdef __cplusplus
}
#endif

#endif /* __INCLUDE_CAN_PROTOCOL_H__ */
