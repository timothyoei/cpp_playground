# Create a library from the lib.cpp file
add_library(myLibrary STATIC lib.cpp)

# Include directories for the library
target_include_directories(myLibrary PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Specify compile options
target_compile_options(myLibrary PRIVATE -Wall -Wextra -Wpedantic)
