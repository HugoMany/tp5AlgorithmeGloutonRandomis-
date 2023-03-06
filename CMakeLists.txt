project(AlgorithmGloutonRandomis)

set(CMAKE_CXX_STANDARD 20)


file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.hpp")

add_executable(AlgorithmGloutonRandomis ${SOURCES} "src/readingMatrix.cpp")