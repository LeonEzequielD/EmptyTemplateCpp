#!/bin/bash

mkdir _build
cd _build
conan install ..
cmake .. -DTRAVISCI=ON
cmake --build . --config release
#make check
make install
