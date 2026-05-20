cmake_minimum_required(VERSION 3.20)
project(esercitazione8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(esempio main.cpp)
target_link_libraries(esempio Eigen3::Eigen)

add_executable(test_gradiente_coniugato test_gradiente_coniugato.cpp)
target_link_libraries(test_gradiente_coniugato Eigen3::Eigen)

add_test(NAME gradiente_coniugato COMMAND test_gradiente_coniugato)

enable_testing()