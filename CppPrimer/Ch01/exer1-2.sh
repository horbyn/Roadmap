#!/bin/bash

set -v

g++ exer1-2.cpp -std=c++11 -o test.out
./test.out
echo $?