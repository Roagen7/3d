//
// Created by roagen on 21.08.2021.
//

#include "Scene.h"

void Scene::buildFrame(Matrix globalTransformMatrix, Matrix projectionMatrix) {
    this->transform(globalTransformMatrix);
    this->applyLight();
    this->project(projectionMatrix);
    this->painterSort();



}

void Scene::project(Matrix matrix) {


    for(auto tri : this->trisTransformed){

//        if(VectorUtils::dot(tri.normal(), ray) < 0.f){
            Triangle triProj = tri.transform(matrix);
            triProj.lum = tri.lum;
            triProj.v[0] += sf::Vector3(1.0,1.0,0.0);
            triProj.v[1] += sf::Vector3(1.0,1.0,0.0);
            triProj.v[2] += sf::Vector3(1.0,1.0,0.0);
            triProj.v[0] *= 400.0;
            triProj.v[1] *= 400.0;
            triProj.v[2] *= 400.0;

            this->trisProjected.push_back(triProj);
//        }


    }


}

void Scene::transform(Matrix matrix) {
    sf::Vector3<double> camera = {0,0,0};
    for(const auto& m : this->meshes){
        for(auto tri : m.getTriangles()){
            tri = tri.transform(matrix);
            auto ray = tri.v[1] - camera;
//
//            if(VectorUtils::dot(tri.normal(), ray) >= 0.0){
//                continue;
//            }

            this->trisTransformed.push_back(tri);
        }
    }
}

void Scene::cleanup() {

    this->trisProjected.clear();
    this->trisTransformed.clear();
}

void Scene::pushMesh(const Mesh& m) {
    this->meshes.push_back(m);
}

std::vector<Triangle> Scene::getBuiltTris() {

    return this->trisProjected;
}

void Scene::applyLight() {
    sf::Vector3<double> lightDir(0.0, 1.0, -1.0);
    lightDir = VectorUtils::normalize(lightDir);

    for(auto& tri : this->trisTransformed){
        auto normal = tri.normal();
        auto lum = VectorUtils::dot(normal, lightDir);
        tri.lum = std::max(0.1,lum);
    }
}

void Scene::painterSort() {
    sort(this->trisProjected.begin(), this->trisProjected.end(), [](Triangle &t1, Triangle &t2)
    {
        float z1 = (t1.v[0].z + t1.v[1].z + t1.v[2].z) / 3.0f;
        float z2 = (t2.v[0].z + t2.v[1].z + t2.v[2].z) / 3.0f;
        return z1 > z2;
    });
}
