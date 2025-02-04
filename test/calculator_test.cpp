#include <gtest/gtest.h>
#include "../include/calculator.h"
#include <climits>
// CalculatorTest is a test fixture, meaning it's a reusable setup for multiple test cases
// it inherits from testing::Test, which is a base class provided by Google Test
// Google Test will automatically call setup and teardown methods if they exist (like SetUp() and TearDown())
class CalculatorTest : public ::testing::Test{
    protected:
        Calculator calc;
};
// test case is written using TEST_F (Test Fixture), which allows tests to use the shared test fixture
TEST_F(CalculatorTest, AddTest) {
    EXPECT_EQ(calc.add(5, 3), 8);       // Positive numbers
    EXPECT_EQ(calc.add(-1, 11), 10);    // Negative and positive numbers
    EXPECT_EQ(calc.add(0, 0), 0);       // Zero addition
    EXPECT_EQ(calc.add(0, -5), -5);     // Zero and negative number
    EXPECT_EQ(calc.add(1000, 2000), 3000); // Larger numbers
}

TEST_F(CalculatorTest, SubtractTest) {
    EXPECT_EQ(calc.subtract(5, 3), 2);        // Positive numbers
    EXPECT_EQ(calc.subtract(-1, 11), -12);    // Negative and positive numbers
    EXPECT_EQ(calc.subtract(0, 0), 0);        // Zero subtraction
    EXPECT_EQ(calc.subtract(0, -5), 5);       // Zero and negative number
    EXPECT_EQ(calc.subtract(1000, 500), 500); // Larger numbers
    EXPECT_EQ(calc.subtract(-10, -5), -5);   // Negative numbers
}

TEST_F(CalculatorTest, AddEdgeCases) {
    EXPECT_EQ(calc.add(INT_MAX, 0), INT_MAX);   // Adding with maximum integer value
    EXPECT_EQ(calc.add(INT_MIN, 0), INT_MIN);   // Adding with minimum integer value
    EXPECT_EQ(calc.add(1, -1), 0);              // Addition of positive and negative number
}

TEST_F(CalculatorTest, SubtractEdgeCases) {
    EXPECT_EQ(calc.subtract(INT_MAX, 1), INT_MAX - 1); // Subtracting from max integer
    EXPECT_EQ(calc.subtract(INT_MIN, -1), INT_MIN + 1); // Subtracting from min integer
    EXPECT_EQ(calc.subtract(1, -1), 2);              // Subtracting negative number
}

TEST_F(CalculatorTest, AddOverflow) {
    EXPECT_EQ(calc.add(INT_MAX, 1), INT_MIN); // Overflow test
}

TEST_F(CalculatorTest, SubtractOverflow) {
    EXPECT_EQ(calc.subtract(INT_MIN, 1), INT_MAX); // Underflow test
}


