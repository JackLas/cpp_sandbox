cmake_minimum_required(VERSION 3.0)

project(cpp_sandbox)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra")

add_subdirectory(HelloWorld)
add_subdirectory(ExplicitConstructor)
add_subdirectory(Move)
add_subdirectory(RVO)
add_subdirectory(ThreadPool)
add_subdirectory(VirtualDestructors)
