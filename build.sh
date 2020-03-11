#!/bin/bash

# Build the compiler
#
# You MUST replace the following commands with the commands for building your compiler

#generate the makefile
rm -rf ./build
mkdir ./build
cd ./build
cmake ..

make