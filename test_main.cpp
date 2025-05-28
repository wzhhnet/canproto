
#include <gtest/gtest.h>
#include "can_proto.c"
#include "intel.c"
#include "motorola.c"

struct can_format_t kCanFmtTab[] = {
    {1, CAN_BIG_ENDIAN, 8, 0, 7, 0, 0},
    {2, CAN_BIG_ENDIAN, 8, 1, 7, 1, 0},
    {3, CAN_BIG_ENDIAN, 3, 2, 7, 2, 5},
    {4, CAN_BIG_ENDIAN, 13, 2, 4, 3, 0},
    {5, CAN_BIG_ENDIAN, 8, 4, 7, 4, 0},
    {6, CAN_BIG_ENDIAN, 8, 5, 7, 5, 0},
    {7, CAN_BIG_ENDIAN, 8, 6, 7, 6, 0},
    {8, CAN_BIG_ENDIAN, 8, 7, 7, 7, 0},

    {1, CAN_LITTLE_ENDIAN, 10, 1, 1, 0, 0},
    {2, CAN_LITTLE_ENDIAN, 2, 1, 3, 1, 2},
    {3, CAN_LITTLE_ENDIAN, 1, 1, 4, 1, 4},
    {4, CAN_LITTLE_ENDIAN, 8, 2, 4, 1, 5},
    {5, CAN_LITTLE_ENDIAN, 1, 2, 5, 2, 5},
    {6, CAN_LITTLE_ENDIAN, 4, 3, 1, 2, 6},
    {7, CAN_LITTLE_ENDIAN, 32, 7, 1, 3, 2},
    {8, CAN_LITTLE_ENDIAN, 6, 7, 7, 7, 2},
};

struct can_frame_t kCanFrmTab[2] = {};

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(can_proto, big_endian)
{
    int rc = 0;
    can_frame_t *frame = &kCanFrmTab[CAN_BIG_ENDIAN];
    set_can_endian(CAN_BIG_ENDIAN); // Big-endian

    // Encode data
    for (int i = 0; i < 8; ++i) {
        can_format_t *fmt = &kCanFmtTab[i];
        rc = encode_can_data(fmt, frame, 1);
        EXPECT_EQ(rc, RC_SUCCESS);
    }
    // Decode data
    for (int i = 0; i < 8; ++i) {
        uint32_t v = 0;
        can_format_t *fmt = &kCanFmtTab[i];
        rc = decode_can_data(fmt, frame, &v);
        EXPECT_EQ(rc, RC_SUCCESS);
        EXPECT_EQ(v, 1);
    }
}

TEST(can_proto, little_endian)
{
    int rc = 0;
    can_frame_t *frame = &kCanFrmTab[CAN_LITTLE_ENDIAN];
    set_can_endian(CAN_LITTLE_ENDIAN); // Little-endian
    
    // Encode data
    for (int i = 8; i < 16; ++i) {
        can_format_t *fmt = &kCanFmtTab[i];
        rc = encode_can_data(fmt, frame, 1);
        EXPECT_EQ(rc, RC_SUCCESS);
    }
    // Decode data
    for (int i = 8; i < 16; ++i) {
        uint32_t v = 0;
        can_format_t *fmt = &kCanFmtTab[i];
        rc = decode_can_data(fmt, frame, &v);
        EXPECT_EQ(rc, RC_SUCCESS);
        EXPECT_EQ(v, 1);
    }
}

TEST(sample, motorala)
{
    motorola_init();
    motorola_set_m_signal_1(0x01);
    motorola_set_m_signal_2(0x01);
    motorola_set_m_signal_3(0x01);
    motorola_set_m_signal_4(0x01);
    motorola_set_m_signal_5(0x01);
    motorola_set_m_signal_6(0x01);
    motorola_set_m_signal_7(0x01);
    motorola_set_m_signal_8(0x01);
    EXPECT_EQ(motorola_get_m_signal_1(), 0x01);
    EXPECT_EQ(motorola_get_m_signal_2(), 0x01);
    EXPECT_EQ(motorola_get_m_signal_3(), 0x01);
    EXPECT_EQ(motorola_get_m_signal_4(), 0x01);
    EXPECT_EQ(motorola_get_m_signal_5(), 0x01);
    EXPECT_EQ(motorola_get_m_signal_6(), 0x01);
    EXPECT_EQ(motorola_get_m_signal_7(), 0x01);
    EXPECT_EQ(motorola_get_m_signal_8(), 0x01);
}

TEST(sample, intel)
{
    intel_init();
    intel_set_i_signal_1(0x01);
    intel_set_i_signal_2(0x01);
    intel_set_i_signal_3(0x01);
    intel_set_i_signal_4(0x01);
    intel_set_i_signal_5(0x01);
    intel_set_i_signal_6(0x01);
    intel_set_i_signal_7(0x01);
    intel_set_i_signal_8(0x01);
    EXPECT_EQ(intel_get_i_signal_1(), 0x01);
    EXPECT_EQ(intel_get_i_signal_2(), 0x01);
    EXPECT_EQ(intel_get_i_signal_3(), 0x01);
    EXPECT_EQ(intel_get_i_signal_4(), 0x01);
    EXPECT_EQ(intel_get_i_signal_5(), 0x01);
    EXPECT_EQ(intel_get_i_signal_6(), 0x01);
    EXPECT_EQ(intel_get_i_signal_7(), 0x01);
    EXPECT_EQ(intel_get_i_signal_8(), 0x01);
}