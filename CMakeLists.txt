cmake_minimum_required(VERSION 3.20)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML REQUIRED system window graphics)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/CMakeFiles/${PROJECT_NAME}.dir)


add_executable(untitled3 main.cpp src/Engine.cpp src/Engine.h src/mesh/Mesh.cpp src/mesh/Mesh.h src/transformation/Matrix.cpp src/transformation/Matrix.h src/mesh/Triangle.cpp src/mesh/Triangle.h src/scene/Scene.cpp src/scene/Scene.h src/transformation/VectorUtils.cpp src/transformation/VectorUtils.h usage/TestScene.cpp usage/TestScene.h src/spatial/light/Light.cpp src/spatial/light/Light.h src/spatial/collider/Collider.cpp src/spatial/collider/Collider.h src/spatial/collider/AABBCollider.cpp src/spatial/collider/AABBCollider.h src/spatial/collider/SphereCollider.cpp src/spatial/collider/SphereCollider.h src/spatial/camera/Camera.cpp src/spatial/camera/Camera.h src/mesh/material/Material.cpp src/mesh/material/Material.h src/mesh/material/Texture.cpp src/mesh/material/Texture.h src/transformation/Clip.cpp src/transformation/Clip.h usage/GravityScene.cpp usage/GravityScene.h usage/CollisionScene.cpp usage/CollisionScene.h src/node/Node.cpp src/node/Node.h usage/SmallScene.cpp usage/SmallScene.h src/spatial/light/Reflection.cpp src/spatial/light/Reflection.h src/config/Environment.cpp src/config/Environment.h)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-window)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})