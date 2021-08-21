//
// Created by roagen on 21.08.2021.
//

#include "Mesh.h"

Mesh Mesh::getUnitCube() {
    auto cube = Mesh();
//    cube.pushTriangle({{0.0,0.0,0.0}, {0.0,1.0,0.0}, {1.0,1.0,0.0}});
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

void Mesh::pushTriangle(triangle tri) {
    this->triangles.push_back(tri);
}

void Mesh::setMesh(std::vector<triangle> tris) {
    this->triangles = std::move(tris);
}

const std::vector<triangle> &Mesh::getTriangles() const {
    return this->triangles;
}


std::vector<triangle> Mesh::getTrianglesProjected(float theta) {

    std::vector<triangle> trianglesProjected;
    auto proj = Matrix::getProjectionMatrix();
    auto rot = Matrix::getRotationMatrixAxisX(theta);
    auto rotZ = Matrix::getRotationMatrixAxisZ(theta);
    auto trans = Matrix::getTranslationMarix({5.0,5.0,10.0});
    auto transform = rot * rotZ;
    transform = transform * trans;
    for(auto tri : this->triangles){
        triangle triProj, triTrans, triRotX, triRotZ;
        triTrans = this->transformTriangle(tri, transform);
        triProj = this->transformTriangle(triTrans, proj);



        std::get<0>(triProj) *= 800.0;
        std::get<1>(triProj) *= 800.0;
        std::get<2>(triProj) *= 800.0;



        trianglesProjected.push_back(triProj);

    }





    return trianglesProjected;
}

triangle Mesh::transformTriangle(triangle tri, Matrix m) {
    return {m.multiplyByVector(std::get<0>(tri)), m.multiplyByVector(std::get<1>(tri)),m.multiplyByVector(std::get<2>(tri))};
}
