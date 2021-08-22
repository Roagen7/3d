//
// Created by roagen on 21.08.2021.
//

#ifndef UNTITLED3_MESH_H
#define UNTITLED3_MESH_H
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <tuple>

#include "../transformation/Matrix.h"
#include "../transformation/VectorUtils.h"
#include "Triangle.h"
#include <utility>
#include <fstream>
#include <iostream>
#include <strstream>


class Mesh {
private:
    std::vector<Triangle> triangles;

public:

    Matrix localTransform = Matrix::getIdentityMatrix();
    void pushTriangle(Triangle tri);
    void setMesh(std::vector<Triangle> tris);
    static Mesh getUnitCube();
    static Mesh loadFromObj(std::string filename);

    [[nodiscard]] const std::vector<Triangle> &getTriangles() const;
    std::vector<Triangle> getTrianglesProjected(float theta);


};


#endif //UNTITLED3_MESH_H
