cmake_minimum_required(VERSION 3.29.2)
project(cypher-saga VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_BUILD_TYPE Release) # optimized no debug symbols and command is: cmake --build . --config Release, smallest, 
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON) # remove unused codes

# Add all source files
add_executable(${PROJECT_NAME}
    src/Main.cpp
    src/imp/ASCIIHandler.cpp
    src/imp/Encryptor.cpp
    src/imp/UI.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)