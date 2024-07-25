#!/bin/bash

cmake -G Ninja -D CMAKE_CXX_COMPILER=g++-14 -B build

ninja -C build

# Check if exactly one argument is passed
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

# Check if the argument is a number
if ! [[ "$1" =~ ^-?[0-9]+$ ]]; then
    echo "Error: Argument is not a valid number."
    exit 1
fi

# Print the number
./build/ch$1/ch$1