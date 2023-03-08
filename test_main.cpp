#include <gtest/gtest.h>

#include <unistd.h>
#include <gtest/gtest.h>
#include "sample.c"

class GlobalTest : public testing::Environment
{
  public:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};

GTEST_API_ int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::Environment *env = new GlobalTest();
    testing::AddGlobalTestEnvironment(env); 
    return RUN_ALL_TESTS();
}

TEST(sample, frame01_set_field_3)
{
    frame01_set_field_3(2);
    EXPECT_EQ(frame01_get_field_3(), 2);
}



