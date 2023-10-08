#!/bin/bash

set -v

g++ exer6-26.cpp -std=c++11 -o test.out
./test.out -d -o ofile data0
