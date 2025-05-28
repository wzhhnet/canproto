/*
 * File: motorola.c
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
#include "motorola.h"
#include "can_proto.h"

static const struct can_format_t kMotorolaFmtTab[] = {
    {M_SIGNAL_1,MOTOROLA,1,0,7,0,7},
    {M_SIGNAL_2,MOTOROLA,2,0,6,0,5},
    {M_SIGNAL_3,MOTOROLA,5,0,4,0,0},
    {M_SIGNAL_4,MOTOROLA,7,1,7,1,1},
    {M_SIGNAL_5,MOTOROLA,32,1,0,5,1},
    {M_SIGNAL_6,MOTOROLA,6,5,0,6,3},
    {M_SIGNAL_7,MOTOROLA,8,6,2,7,3},
    {M_SIGNAL_8,MOTOROLA,3,7,2,7,0},
};

static struct can_frame_t kMotorolaFrmTab[MOTOROLA_FRAME_COUNT] = {};

static const struct can_format_t* FindMotorolaFormat(uint8_t frm_id, uint8_t sig_id)
{
    int l = sizeof(kMotorolaFmtTab)/sizeof(struct can_format_t);
    for (int i = 0; i < l; ++i) {
        if (kMotorolaFmtTab[i].frame_id == frm_id
           && kMotorolaFmtTab[i].field_id == sig_id) {
            return &kMotorolaFmtTab[i];
        }
    }
    return (struct can_format_t*)0;
}
const struct can_frame_t* motorola_frames()
{
    return kMotorolaFrmTab;
}

void motorola_init()
{
    set_can_endian(CAN_BIG_ENDIAN);
    memset(kMotorolaFrmTab, 0, sizeof(kMotorolaFrmTab));
}

void motorola_set_m_signal_1(unsigned int v)
{
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_1);
    encode_can_data(fmt,  &kMotorolaFrmTab[MOTOROLA], v);
}

unsigned int motorola_get_m_signal_1()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_1);
    decode_can_data(fmt, &kMotorolaFrmTab[MOTOROLA], &v);
    return v;
}

void motorola_set_m_signal_2(unsigned int v)
{
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_2);
    encode_can_data(fmt,  &kMotorolaFrmTab[MOTOROLA], v);
}

unsigned int motorola_get_m_signal_2()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_2);
    decode_can_data(fmt, &kMotorolaFrmTab[MOTOROLA], &v);
    return v;
}

void motorola_set_m_signal_3(unsigned int v)
{
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_3);
    encode_can_data(fmt,  &kMotorolaFrmTab[MOTOROLA], v);
}

unsigned int motorola_get_m_signal_3()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_3);
    decode_can_data(fmt, &kMotorolaFrmTab[MOTOROLA], &v);
    return v;
}

void motorola_set_m_signal_4(unsigned int v)
{
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_4);
    encode_can_data(fmt,  &kMotorolaFrmTab[MOTOROLA], v);
}

unsigned int motorola_get_m_signal_4()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_4);
    decode_can_data(fmt, &kMotorolaFrmTab[MOTOROLA], &v);
    return v;
}

void motorola_set_m_signal_5(unsigned int v)
{
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_5);
    encode_can_data(fmt,  &kMotorolaFrmTab[MOTOROLA], v);
}

unsigned int motorola_get_m_signal_5()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_5);
    decode_can_data(fmt, &kMotorolaFrmTab[MOTOROLA], &v);
    return v;
}

void motorola_set_m_signal_6(unsigned int v)
{
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_6);
    encode_can_data(fmt,  &kMotorolaFrmTab[MOTOROLA], v);
}

unsigned int motorola_get_m_signal_6()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_6);
    decode_can_data(fmt, &kMotorolaFrmTab[MOTOROLA], &v);
    return v;
}

void motorola_set_m_signal_7(unsigned int v)
{
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_7);
    encode_can_data(fmt,  &kMotorolaFrmTab[MOTOROLA], v);
}

unsigned int motorola_get_m_signal_7()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_7);
    decode_can_data(fmt, &kMotorolaFrmTab[MOTOROLA], &v);
    return v;
}

void motorola_set_m_signal_8(unsigned int v)
{
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_8);
    encode_can_data(fmt,  &kMotorolaFrmTab[MOTOROLA], v);
}

unsigned int motorola_get_m_signal_8()
{
    unsigned int v = 0;
    const struct can_format_t *fmt = FindMotorolaFormat(MOTOROLA, M_SIGNAL_8);
    decode_can_data(fmt, &kMotorolaFrmTab[MOTOROLA], &v);
    return v;
}
