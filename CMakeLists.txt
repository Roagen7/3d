cmake_minimum_required(VERSION 3.20)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML REQUIRED system window graphics)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(untitled3 main.cpp src/Engine.cpp src/Engine.h src/Mesh.cpp src/Mesh.h src/Matrix.cpp src/Matrix.h src/Triangle.cpp src/Triangle.h)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-window)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})