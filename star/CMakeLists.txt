cmake_minimum_required(VERSION 3.24)
project(star)

set(CMAKE_CXX_STANDARD 20)

add_executable(star main.cpp general.cpp)
add_executable(star_calc main.cpp calc.cpp)

add_library(calc_library STATIC calc.cpp)

target_include_directories(star_calc PUBLIC includes/math)
target_include_directories(star_calc PUBLIC includes/general)

target_include_directories(calc_library PUBLIC includes/math)

find_library(CALC_LIB calc_library lib)
target_link_libraries(star LINK_PUBLIC ${CALC_LIB})

add_subdirectory(tests)