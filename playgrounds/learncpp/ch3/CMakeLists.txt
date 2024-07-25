add_executable(ch3 ch3.cpp)

target_include_directories(ch3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(ch3 PRIVATE -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic -pedantic-errors -ggdb)
