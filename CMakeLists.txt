cmake_minimum_required(VERSION 3.8)
project(codes)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES test2.cpp)
add_executable(code ${SOURCE_FILES})
add_executable(test1 test1.cpp)
add_executable(test_spoj test_spoj.cpp)
add_executable(check_binarytree_is_subtree trees/check_binarytree_is_subtree.cpp)