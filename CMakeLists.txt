project(AlgorithmGloutonRandomis)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)


file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.hpp")

add_executable(AlgorithmGloutonRandomis ${SOURCES} "src/matrice.cpp")