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
#include "material/Material.h"

#include <utility>
#include <fstream>
#include <iostream>
#include <strstream>


class Mesh {

public:
    std::vector<Triangle> triangles;
    Material* material = nullptr;

    Matrix localTransform = Matrix::getIdentityMatrix();
    void pushTriangle(Triangle tri);
    void setMesh(std::vector<Triangle> tris);
    static Mesh getUnitCube();
    static Mesh getUnitCubeTextured();
    static Mesh loadFromObj(const std::string& filename, bool hasTexture = false);

    [[nodiscard]] const std::vector<Triangle> &getTriangles() const;
    std::vector<Triangle> getTrianglesProjected(float theta);


};


#endif //UNTITLED3_MESH_H
