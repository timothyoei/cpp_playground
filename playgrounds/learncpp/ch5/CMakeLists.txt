add_executable(ch5 ch5.cpp)

target_include_directories(ch5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(ch5 PRIVATE -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic -pedantic-errors -ggdb)
