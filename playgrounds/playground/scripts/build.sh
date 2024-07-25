#!/bin/bash

cmake -G Ninja -D CMAKE_CXX_COMPILER=g++ -B build

ninja -C build

./build/src/myExecutable

rm -rf build