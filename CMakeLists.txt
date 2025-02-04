cmake_minimum_required(VERSION 3.10)

project(testing_project)

set(CMAKE_CXX_STANDARD 14)

# Include directories
include_directories(include test)

# Find GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

# Add the main project executable
add_executable(testing_project src/main.cpp src/calculator.cpp)
target_link_libraries(testing_project GTest::GTest GTest::Main pthread)

# Add test executable (make sure to include calculator.cpp!)
add_executable(test_runner test/calculator_test.cpp src/calculator.cpp)
target_link_libraries(test_runner GTest::GTest GTest::Main pthread)

# Register tests
add_test(NAME CalculatorTests COMMAND test_runner)
