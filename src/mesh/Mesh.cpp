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
    sf::Vector3<double> camera = {0.0,0.0,-1.0};
//    vector<triangle> vecTrianglesToRaster;
    for(auto tri : this->triangles){
        Triangle triProj, triTrans, triRotX, triRotZ;
        triTrans = tri.transform(transform);

        auto ray = triTrans.v[0] - camera;




        sf::Vector3<double> normal;
        auto line1 = triTrans.v[1] - triTrans.v[0];
        auto line2 = triTrans.v[2] - triTrans.v[0];

        normal.x = line1.y * line2.z - line1.z * line2.y;
        normal.y = line1.z * line2.x - line1.x * line2.z;
        normal.z = line1.x * line2.y - line1.y * line2.x;
        float l = sqrtf(normal.x*normal.x + normal.y*normal.y + normal.z*normal.z);
        normal.x /= l; normal.y /= l; normal.z /= l;
        normal = triTrans.normal();

        if(VectorUtils::dot(normal,ray) < 0.0){
            triProj = triTrans.transform(proj);
            triProj.v[0] += sf::Vector3(1.0,1.0,0.0);
            triProj.v[1] += sf::Vector3(1.0,1.0,0.0);
            triProj.v[2] += sf::Vector3(1.0,1.0,0.0);

            triProj.v[0] *= 400.0;
            triProj.v[1] *= 400.0;
            triProj.v[2] *= 400.0;
            //        std::cout << triProj.v[0].y << std::endl;
            triProj.lum = VectorUtils::dot(normal, {0,0,-1});


//            vecTrianglesToRaster.push_back(triProjected);
            trianglesProjected.push_back(triProj);

        }





    }





    return trianglesProjected;
}
