#!/bin/bash

#Compilation process
cd build/
cmake ../ -DMY_COMPILE_NAME=$1
make
cd ../

#Excution process
time ./build/$1
rm ./build/$1
