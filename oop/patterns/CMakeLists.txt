cmake_minimum_required(VERSION 2.8)

project(patterns)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic-errors")

add_executable("strategy" "strategy.cpp")
add_executable("observer" "observer.cpp")
add_executable("decorator" "decorator.cpp")
add_executable("factory_method" "factory-method.cpp")
