cmake_minimum_required(VERSION 3.26)

project(Matrix VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.2 
)
FetchContent_MakeAvailable(Catch2)


add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE matrix)

#----------------testing---------------------------------------------------------------
# add_executable(tests_matrix1d tests/tests_matrix1d.cpp)
# target_include_directories(tests_matrix1d PRIVATE matrix)
# target_link_libraries(tests_matrix1d PRIVATE Catch2::Catch2WithMain)

# add_executable(tests_matrix2d tests/tests_matrix2d.cpp)
# target_include_directories(tests_matrix2d PRIVATE matrix)
# target_link_libraries(tests_matrix2d PRIVATE Catch2::Catch2WithMain)

# add_executable(tests_matrix3d tests/tests_matrix3d.cpp)
# target_include_directories(tests_matrix3d PRIVATE matrix)
# target_link_libraries(tests_matrix3d PRIVATE Catch2::Catch2WithMain)

add_executable(tests tests/tests_matrix1d.cpp tests/tests_matrix2d.cpp tests/tests_matrix3d.cpp)
target_include_directories(tests PRIVATE matrix)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)
# catch_discover_tests(tests_matrix1d)
# catch_discover_tests(tests_matrix2d)
# catch_discover_tests(tests_matrix3d)