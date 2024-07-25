add_executable(ch2 ch2.cpp)

target_include_directories(ch2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(ch2 PRIVATE -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic -pedantic-errors -ggdb)
