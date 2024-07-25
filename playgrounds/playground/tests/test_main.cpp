#include <gtest/gtest.h>
#include "lib.hpp"

TEST(HelloTest, BasicAssertions) {
  EXPECT_EQ(5, hello2());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
