add_executable(ch1 ch1.cpp)

target_include_directories(ch1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(ch1 PRIVATE -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic -pedantic-errors -ggdb)
