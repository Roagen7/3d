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
#include <iostream>


class Mesh {
private:
    std::vector<Triangle> triangles;

public:

    void pushTriangle(Triangle tri);
    void setMesh(std::vector<Triangle> tris);
    static Mesh getUnitCube();
    [[nodiscard]] const std::vector<Triangle> &getTriangles() const;
    std::vector<Triangle> getTrianglesProjected(float theta);


};


#endif //UNTITLED3_MESH_H
