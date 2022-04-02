cmake_minimum_required(VERSION 3.10)
project(LDGame VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SourceCode
    source/application/application.cc
    )

add_executable(LDGame source/entry-point.cc ${SourceCode})

target_include_directories(LDGame PUBLIC
    source/application
   )