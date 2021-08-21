//
// Created by roagen on 21.08.2021.
//

#ifndef UNTITLED3_MESH_H
#define UNTITLED3_MESH_H
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <tuple>

#include "Matrix.h"
#include <utility>
#include <iostream>

typedef std::tuple<sf::Vector3<double>,sf::Vector3<double>, sf::Vector3<double>> triangle;
class Mesh {
private:
    std::vector<triangle> triangles;



public:

    void pushTriangle(triangle tri);
    void setMesh(std::vector<triangle> tris);
    static Mesh getUnitCube();
    [[nodiscard]] const std::vector<triangle> &getTriangles() const;
    std::vector<triangle> getTrianglesProjected(float theta);
    triangle transformTriangle(triangle tri, Matrix m);

};


#endif //UNTITLED3_MESH_H
