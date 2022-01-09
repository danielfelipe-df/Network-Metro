#!/bin/bash

# Get parameters
while getopts f:i:e:c:t: option
do
    case "${option}"
    in
        f)filename=${OPTARG};;
        i)init=${OPTARG};;
	e)end=${OPTARG};;
	c)color=${OPTARG};;
	t)tests=${OPTARG};;
    esac
done


# Change the values in the file
sed -i "s%^  this->filename =.*%  this->filename = \"${filename}\";%" ../src/parameters.cpp
sed -i "s%^  this->init =.*%  this->init = \"${init^^}\";%" ../src/parameters.cpp
sed -i "s%^  this->end =.*%  this->end = \"${end^^}\";%" ../src/parameters.cpp
sed -i "s%^  this->color =.*%  this->color = \"${color^^}\";%" ../src/parameters.cpp


# Compilation process
if [ ! -d build ]; then
    mkdir build
fi
cd build/
cmake ../
make
cd ../


# Excution process
time ./build/tests
rm ./build/tests
