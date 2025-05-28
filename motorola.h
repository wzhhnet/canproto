/*
 * File: motorola.h
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
#ifdef __cplusplus
extern "C" {
#endif


#define    MOTOROLA_FRAME_COUNT    1

enum motorola_frame_e {
    MOTOROLA,
};

enum motorola_signal_e {
    M_SIGNAL_1,
    M_SIGNAL_2,
    M_SIGNAL_3,
    M_SIGNAL_4,
    M_SIGNAL_5,
    M_SIGNAL_6,
    M_SIGNAL_7,
    M_SIGNAL_8,
};

const struct can_frame_t* motorola_frames();

void motorola_init();

void motorola_set_m_signal_1(unsigned int v);

unsigned int motorola_get_m_signal_1();

void motorola_set_m_signal_2(unsigned int v);

unsigned int motorola_get_m_signal_2();

void motorola_set_m_signal_3(unsigned int v);

unsigned int motorola_get_m_signal_3();

void motorola_set_m_signal_4(unsigned int v);

unsigned int motorola_get_m_signal_4();

void motorola_set_m_signal_5(unsigned int v);

unsigned int motorola_get_m_signal_5();

void motorola_set_m_signal_6(unsigned int v);

unsigned int motorola_get_m_signal_6();

void motorola_set_m_signal_7(unsigned int v);

unsigned int motorola_get_m_signal_7();

void motorola_set_m_signal_8(unsigned int v);

unsigned int motorola_get_m_signal_8();

#ifdef __cplusplus
}
#endif
