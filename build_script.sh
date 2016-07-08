#!/bin/bash

if [ "$#" -eq  "0" ]
then
    mkdir _build
    cd _build
    conan install ..
    cmake ..
    cmake --build . --config release
    echo "-----------------------------------------------------------"
    valgrind --leak-check=full --error-exitcode=1 ./bin/test-empty-template
    echo "-----------------------------------------------------------"
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


