cmake_minimum_required(VERSION 3.20)
project(esercitazione7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAG} -Wall -Wshadow -Werror=vla")

add_executable(es_dijkstra main.cpp)