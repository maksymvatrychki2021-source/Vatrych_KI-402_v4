#include <gtest/gtest.h>  

int add(int a, int b);

TEST(AddFunctionTest, HandlesPositiveInput) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(100, 200), 300);
}

TEST(AddFunctionTest, HandlesNegativeInput) {
    EXPECT_EQ(add(-1, -1), -2);
    EXPECT_EQ(add(-1, 1), 0);
}

TEST(AddFunctionTest, HandlesZeroInput) {
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(0, 1), 1);
    EXPECT_EQ(add(1, 0), 1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
