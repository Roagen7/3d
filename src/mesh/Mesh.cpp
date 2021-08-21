//
// Created by roagen on 21.08.2021.
//

#include "Mesh.h"

Mesh Mesh::getUnitCube() {
    auto cube = Mesh();

cube.setMesh({{{ 0.0f, 0.0f, 0.0f },   {0.0f, 1.0f, 0.0f},    {1.0f, 1.0f, 0.0f} },
              { {0.0f, 0.0f, 0.0f},    {1.0f, 1.0f, 0.0f},    {1.0f, 0.0f, 0.0f} },

              { {1.0f, 0.0f, 0.0f},   { 1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f} },
              { {1.0f, 0.0f, 0.0f},   {1.0f, 1.0f, 1.0f},   {1.0f, 0.0f, 1.0f} },


              { {1.0f, 0.0f, 1.0f},   {1.0f, 1.0f, 1.0f},   {0.0f, 1.0f, 1.0f} },
              { {1.0f, 0.0f, 1.0f},    {0.0f, 1.0f, 1.0f},   {0.0f, 0.0f, 1.0f} },


              { {0.0f, 0.0f, 1.0f},    {0.0f, 1.0f, 1.0f},    {0.0f, 1.0f, 0.0f} },
              { {0.0f, 0.0f, 1.0f},    {0.0f, 1.0f, 0.0f},    {0.0f, 0.0f, 0.0f} },


              { {0.0f, 1.0f, 0.0f},    {0.0f, 1.0f, 1.0f},    {1.0f, 1.0f, 1.0f} },
              { {0.0f, 1.0f, 0.0f},    {1.0f, 1.0f, 1.0f},    {1.0f, 1.0f, 0.0f} },


              { {1.0f, 0.0f, 1.0f},    {0.0f, 0.0f, 1.0f},    {0.0f, 0.0f, 0.0f} },
              { {1.0f, 0.0f, 1.0f},    {0.0f, 0.0f, 0.0f},    {1.0f, 0.0f, 0.0f }},
              });
    return cube;
}

void Mesh::pushTriangle(Triangle tri) {
    this->triangles.push_back(tri);
}

void Mesh::setMesh(std::vector<Triangle> tris) {
    this->triangles = std::move(tris);
}

const std::vector<Triangle> &Mesh::getTriangles() const {
    return this->triangles;
}


std::vector<Triangle> Mesh::getTrianglesProjected(float theta) {

    std::vector<Triangle> trianglesProjected;
    auto proj = Matrix::getProjectionMatrix();
    auto rot = Matrix::getRotationMatrixAxisX(theta);
    auto rotZ = Matrix::getRotationMatrixAxisZ(theta);
    auto trans = Matrix::getTranslationMarix({0.0,0.0,10.0});
    auto transform = rot * rotZ;
    transform = transform * trans;
    for(auto tri : this->triangles){
        Triangle triProj, triTrans, triRotX, triRotZ;
//
        triProj = tri.transform(transform).transform(proj);
//        triProj = tri.transform(proj);

//        triProj.v[0] += sf::Vector3(1,1,0);
        triProj.v[0] += sf::Vector3(1.0,1.0,0.0);
        triProj.v[1] += sf::Vector3(1.0,1.0,0.0);
        triProj.v[2] += sf::Vector3(1.0,1.0,0.0);

        triProj.v[0] *= 400.0;
        triProj.v[1] *= 400.0;
        triProj.v[2] *= 400.0;
        std::cout << triProj.v[0].y << std::endl;
        trianglesProjected.push_back(triProj);

    }





    return trianglesProjected;
}
