cmake_minimum_required(VERSION 3.14)

project(Qt-task-1 LANGUAGES CXX)

set(POLARLIB_SOURCES polarfunc.h
    polarfunction.cpp polarfunction.h
    archspiralfunc.h archspiralfunc.cpp
    butterflyfunc.h butterflyfunc.cpp)

add_library(PolarFuncLib STATIC ${POLARLIB_SOURCES})
