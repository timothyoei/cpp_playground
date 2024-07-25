# Add the main executable
add_executable(myExecutable main.cpp)

add_subdirectory(lib)

# Link libraries
target_link_libraries(myExecutable PRIVATE myLibrary)

# Include directories for the main executable
target_include_directories(myExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Specify compile options
# target_compile_options(myExecutable PRIVATE -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic -Werror -pedantic-errors -ggdb)
target_compile_options(myExecutable PRIVATE -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic -pedantic-errors -ggdb)


# Release build
# target_compile_options(myExecutable PRIVATE -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic -Werror -pedantic-errors -DNDEBUG -O2)