#include <gtest/gtest.h>  // Include the Google Test framework

// Function prototype for add
int add(int a, int b);

// Test case for the add function
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

// You can add more test cases as needed

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
