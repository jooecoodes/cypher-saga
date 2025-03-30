cmake_minimum_required(VERSION 3.29.2)
project(cypher-saga VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Add all source files
add_executable(${PROJECT_NAME}
    src/Main.cpp
    src/imp/ASCIIHandler.cpp
    src/imp/Encryptor.cpp
    src/imp/UI.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)