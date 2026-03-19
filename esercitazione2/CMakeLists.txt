cmake_minimum_required(VERSION 3.20)
project(esercizio1)
project(esercizio2)
project(esercizio3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAG} -Wall -Wshadow -Werror=vla")

add_executable(esercizio1 esercizio1.cpp)
add_executable(esercizio2 esercizio2.cpp)
add_executable(esercizio3 esercizio3.cpp)