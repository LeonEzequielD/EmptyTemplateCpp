#!/bin/bash

if [ "$#" -eq  "0" ]
then
    mkdir _build
    cd _build
    conan install ..
    cmake ..
    cmake --build . --config release
    cd bin
    valgrind --leak-check=full --error-exitcode=1 --trace-children=yes --show-leak-kinds=all ./test-empty-template
    cd ..
    make utest
    make install
else
    if [[ "$1" ==  "clean" ]]
    then
        rm -rf _*
    else
        echo "ERREI"
    fi
fi


