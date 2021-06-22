cmake_minimum_required(VERSION 3.20)
project(hello_world CXX)
add_executable(main_app main.cpp)
add_executable(testing_dfs dfs.test.cpp dfs.cpp graph.cpp)