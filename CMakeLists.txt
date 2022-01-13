cmake_minimum_required(VERSION 3.16.0)
project(noneuclidean VERSION 0.0.1 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -pedantic)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(
    NonEuclidean
    ${OPENGL_INCLUDE_DIRS}    
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIRS}
)

file(GLOB SRC_FILES "NonEuclidean/*.cpp")

add_executable(main ${SRC_FILES})

target_link_libraries(main
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    glfw
    ${GLFW_LIBRARIES}
)