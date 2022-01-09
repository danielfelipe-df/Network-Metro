#!/bin/bash

# Get parameters
while getopts f:i:e:c: option
do
    case "${option}"
    in
        f)filename=${OPTARG};;
        i)init=${OPTARG};;
	e)end=${OPTARG};;
	c)color=${OPTARG};;
    esac
done


# If the parameter hasn't been passed, then use the default value or stop the program and send message.
if [ -z "$filename" ]; then
    filename="dat/network.csv"
fi

if [ -z "$init" ]; then
    echo "No initial node passed as argument. Please write it."
    exit 127
fi

if [ -z "$end" ]; then
    echo "No final node passed as argument. Please write it."
    exit 127
fi

if [ -z "$color" ]; then
    color="NOCOLOR"
fi


# Print parameters
echo "Filename   : $filename"
echo "First node : $init"
echo "Last node  : $end"
echo "Color      : $color"


# Change the values in the file
sed -i "s%^  this->filename =.*%  this->filename = \"${filename}\";%" src/parameters.cpp
sed -i "s%^  this->init =.*%  this->init = \"${init^^}\";%" src/parameters.cpp
sed -i "s%^  this->end =.*%  this->end = \"${end^^}\";%" src/parameters.cpp
sed -i "s%^  this->color =.*%  this->color = \"${color^^}\";%" src/parameters.cpp


# Compilation process
if [ ! -d build ]; then
    mkdir build
fi
cd build/
cmake ../ -DMY_COMPILE_NAME=x.code
make
cd ../


# Excution process
time ./build/x.code
rm ./build/x.code
