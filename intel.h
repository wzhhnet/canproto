/*
 * File: intel.h
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


#define    INTEL_FRAME_COUNT    1

enum intel_frame_e {
    INTEL,
};

enum intel_signal_e {
    I_SIGNAL_1,
    I_SIGNAL_2,
    I_SIGNAL_3,
    I_SIGNAL_4,
    I_SIGNAL_5,
    I_SIGNAL_6,
    I_SIGNAL_7,
    I_SIGNAL_8,
};

const struct can_frame_t* intel_frames();

void intel_init();

void intel_set_i_signal_1(unsigned int v);

unsigned int intel_get_i_signal_1();

void intel_set_i_signal_2(unsigned int v);

unsigned int intel_get_i_signal_2();

void intel_set_i_signal_3(unsigned int v);

unsigned int intel_get_i_signal_3();

void intel_set_i_signal_4(unsigned int v);

unsigned int intel_get_i_signal_4();

void intel_set_i_signal_5(unsigned int v);

unsigned int intel_get_i_signal_5();

void intel_set_i_signal_6(unsigned int v);

unsigned int intel_get_i_signal_6();

void intel_set_i_signal_7(unsigned int v);

unsigned int intel_get_i_signal_7();

void intel_set_i_signal_8(unsigned int v);

unsigned int intel_get_i_signal_8();

#ifdef __cplusplus
}
#endif
