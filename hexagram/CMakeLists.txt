cmake_minimum_required(VERSION 3.24)
project(hexagram)

set(CMAKE_CXX_STANDARD 20)


find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(hexagram main.cpp)

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} GLEW::GLEW)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)
