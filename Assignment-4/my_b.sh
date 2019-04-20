#!/bin/bash
            if g++ -std=c++11 output_file.cpp 2>temp.err; then echo compilation success ;else echo "There is type mismatch in condition"; fi
