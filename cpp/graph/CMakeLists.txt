cmake_minimum_required(VERSION 3.20)
project(graph CXX)
add_executable(testing_graph graph.test.cpp graph.cpp)
add_executable(testing_dfs dfs.test.cpp dfs.cpp graph.cpp)
add_executable(testing_bfs bfs.test.cpp bfs.cpp graph.cpp)
add_executable(testing_binary_heap binary_heap.test.cpp binary_heap.cpp)
add_executable(testing_dijkstra dijkstra.test.cpp dijkstra.cpp binary_heap.cpp graph.cpp)
add_executable(testing_jarnik_prim jarnik_prim.test.cpp jarnik_prim.cpp graph.cpp binary_heap.cpp)