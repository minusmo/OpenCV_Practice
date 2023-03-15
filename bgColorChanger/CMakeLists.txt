cmake_minimum_required(VERSION 3.24)
project(bgColorChanger)

set(CMAKE_CXX_STANDARD 14)

add_executable(bgColorChanger main.cpp)

find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} GLEW::GLEW)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

include_directories(libs/glad/include)
add_library(glad libs/glad/src/glad.c)

target_link_libraries(${PROJECT_NAME} glad)