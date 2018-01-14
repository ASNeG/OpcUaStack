#!/bin/bash


rm -rf `find . -name \*.h | grep -Eiv BaseObjectType.h`
rm -rf `find . -name \*.cpp | grep -Eiv BaseObjectType.cpp`
