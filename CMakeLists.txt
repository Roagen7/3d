cmake_minimum_required(VERSION 3.20)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML REQUIRED system window graphics)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir)
file(COPY hammer.obj DESTINATION ${CMAKE_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir)

add_executable(untitled3 main.cpp src/Engine.cpp src/Engine.h src/mesh/Mesh.cpp src/mesh/Mesh.h src/transformation/Matrix.cpp src/transformation/Matrix.h src/mesh/Triangle.cpp src/mesh/Triangle.h src/scene/Scene.cpp src/scene/Scene.h src/transformation/VectorUtils.cpp src/transformation/VectorUtils.h)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-window)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})