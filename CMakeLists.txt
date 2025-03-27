cmake_minimum_required(VERSION 3.29.2)
project(cypher-saga VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_executable(${PROJECT_NAME} src/main.cpp)

# add_subdirectory(include)

# target_link_libraries(${PROJECT_NAME} PRIVATE include)
