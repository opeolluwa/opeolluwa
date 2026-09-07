cmake_minimum_required(VERSION 4.4.2)
project(opeolluwa)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include)