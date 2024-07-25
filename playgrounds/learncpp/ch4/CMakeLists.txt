add_executable(ch4 ch4.cpp)

target_include_directories(ch4 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(ch4 PRIVATE -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic -pedantic-errors -ggdb)
