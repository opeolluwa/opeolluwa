cmake_minimum_required(VERSION 4.4.2)
project(opeolluwa)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog
  GIT_TAG    v1.17.0
)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG    v1.18.0
)

FetchContent_MakeAvailable(spdlog googletest)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
  PRIVATE
    src/main.cpp
    src/server.cpp
    src/projects.cpp
    src/controllers.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include third_party)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)

enable_testing()

add_executable(${PROJECT_NAME}_tests)
target_sources(${PROJECT_NAME}_tests
  PRIVATE
    tests/projects_test.cpp
    tests/server_test.cpp
    src/server.cpp
    src/projects.cpp
)

target_include_directories(${PROJECT_NAME}_tests PRIVATE include third_party)
target_link_libraries(${PROJECT_NAME}_tests
  PRIVATE
  GTest::gtest_main
  spdlog::spdlog
)

add_test(NAME ${PROJECT_NAME}_tests COMMAND ${PROJECT_NAME}_tests)
set_tests_properties(${PROJECT_NAME}_tests PROPERTIES
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
