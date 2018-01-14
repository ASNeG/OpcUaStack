#!/bin/bash


rm -rf `find . -name \*.h | grep -Eiv BaseVariableType.h`
rm -rf `find . -name \*.cpp | grep -Eiv BaseVariableType.cpp`
