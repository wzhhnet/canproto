/*
 * File: intel.c
 * Author: CanGenerator
 * Date: 05/28/2025
 * Email: wzhhnet@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the ";License;");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ";AS IS;" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include<string.h>
#include "intel.h"
#include "can_proto.h"

static const struct can_format_t kIntelFmtTab[] = {
    {I_SIGNAL_1,INTEL,1,0,0,0,0},
    {I_SIGNAL_2,INTEL,1,0,1,0,1},
    {I_SIGNAL_3,INTEL,1,0,2,0,2},
    {I_SIGNAL_4,INTEL,5,0,7,0,3},
    {I_SIGNAL_5,INTEL,32,4,7,1,0},
    {I_SIGNAL_6,INTEL,7,5,6,5,0},
    {I_SIGNAL_7,INTEL,8,6,6,5,7},
    {I_SIGNAL_8,INTEL,9,7,7,6,7},
};

static struct can_frame_t kIntelFrmTab[INTEL_FRAME_COUNT] = {};

static const struct can_format_t* FindIntelFormat(uint8_t frm_id, uint8_t sig_id)
{
    int l = sizeof(kIntelFmtTab)/sizeof(struct can_format_t);
    for (int i = 0; i < l; ++i) {
        if (kIntelFmtTab[i].frame_id == frm_id
           && kIntelFmtTab[i].field_id == sig_id) {
            return &kIntelFmtTab[i];
        }
    }
    return (struct can_format_t*)0;
}
const struct can_frame_t* intel_frames()
{
    return kIntelFrmTab;
}

void intel_init()
{
    set_can_endian(CAN_LITTLE_ENDIAN);
    memset(kIntelFrmTab, 0, sizeof(kIntelFrmTab));
}

void intel_set_i_signal_1(unsigned int v)
{
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_1);
    encode_can_data(fmt,  &kIntelFrmTab[INTEL], v);
}

unsigned int intel_get_i_signal_1()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_1);
    decode_can_data(fmt, &kIntelFrmTab[INTEL], &v);
    return v;
}

void intel_set_i_signal_2(unsigned int v)
{
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_2);
    encode_can_data(fmt,  &kIntelFrmTab[INTEL], v);
}

unsigned int intel_get_i_signal_2()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_2);
    decode_can_data(fmt, &kIntelFrmTab[INTEL], &v);
    return v;
}

void intel_set_i_signal_3(unsigned int v)
{
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_3);
    encode_can_data(fmt,  &kIntelFrmTab[INTEL], v);
}

unsigned int intel_get_i_signal_3()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_3);
    decode_can_data(fmt, &kIntelFrmTab[INTEL], &v);
    return v;
}

void intel_set_i_signal_4(unsigned int v)
{
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_4);
    encode_can_data(fmt,  &kIntelFrmTab[INTEL], v);
}

unsigned int intel_get_i_signal_4()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_4);
    decode_can_data(fmt, &kIntelFrmTab[INTEL], &v);
    return v;
}

void intel_set_i_signal_5(unsigned int v)
{
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_5);
    encode_can_data(fmt,  &kIntelFrmTab[INTEL], v);
}

unsigned int intel_get_i_signal_5()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_5);
    decode_can_data(fmt, &kIntelFrmTab[INTEL], &v);
    return v;
}

void intel_set_i_signal_6(unsigned int v)
{
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_6);
    encode_can_data(fmt,  &kIntelFrmTab[INTEL], v);
}

unsigned int intel_get_i_signal_6()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_6);
    decode_can_data(fmt, &kIntelFrmTab[INTEL], &v);
    return v;
}

void intel_set_i_signal_7(unsigned int v)
{
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_7);
    encode_can_data(fmt,  &kIntelFrmTab[INTEL], v);
}

unsigned int intel_get_i_signal_7()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_7);
    decode_can_data(fmt, &kIntelFrmTab[INTEL], &v);
    return v;
}

void intel_set_i_signal_8(unsigned int v)
{
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_8);
    encode_can_data(fmt,  &kIntelFrmTab[INTEL], v);
}

unsigned int intel_get_i_signal_8()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindIntelFormat(INTEL, I_SIGNAL_8);
    decode_can_data(fmt, &kIntelFrmTab[INTEL], &v);
    return v;
}
