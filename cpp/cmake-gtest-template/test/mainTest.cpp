#include "gtest/gtest.h"

TEST(MajorNameTest, MinorNameTest) {
  EXPECT_TRUE(1);
  EXPECT_TRUE(0);
}

class TestClassName : public ::testing::Test {
  protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(TestClassName, TestInstanceName) {
  EXPECT_TRUE(1);
}
