add_executable(ch0 ch0.cpp)

target_include_directories(ch0 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(ch0 PRIVATE -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic -pedantic-errors -ggdb)
