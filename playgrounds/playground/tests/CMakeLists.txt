# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Create a test executable
add_executable(myTests test_main.cpp)

# Link with GoogleTest and the main project library
target_link_libraries(myTests PRIVATE gtest gtest_main myLibrary)

# Add tests
add_test(NAME myTests COMMAND myTests)

# Include directories for the test executable
target_include_directories(myTests PRIVATE ${CMAKE_SOURCE_DIR}/src/lib)
