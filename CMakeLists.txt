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

add_library(Matrix INTERFACE)
target_include_directories(Matrix INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/matrix>)
install(TARGETS Matrix EXPORT MatrixTargets)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION include)
install(EXPORT MatrixTargets FILE MatrixConfig.cmake DESTINATION lib/cmake/Matrix)

# add_executable(main main.cpp)
# target_link_libraries(main PRIVATE Matrix)
# target_include_directories(${PROJECT_NAME} PRIVATE matrix)

#----------------testing---------------------------------------------------------------
add_executable(tests_matrix tests/tests_matrix1d.cpp tests/tests_matrix2d.cpp tests/tests_matrix3d.cpp)
target_include_directories(tests_matrix PRIVATE matrix)
target_link_libraries(tests_matrix PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests_matrix)