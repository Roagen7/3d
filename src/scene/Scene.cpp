//
// Created by roagen on 21.08.2021.
//

#include "Scene.h"

void Scene::buildFrame(Matrix globalTransformMatrix, Matrix projectionMatrix) {
    this->transform(globalTransformMatrix);
    this->project(projectionMatrix);

}

void Scene::project(Matrix matrix) {
    for(auto tri : this->trisTransformed){
        this->trisProjected.push_back(tri.transform(matrix));
    }
}

void Scene::transform(Matrix matrix) {
    for(auto m : this->meshes){
        for(auto tri : m.getTriangles()){
            this->trisTransformed.push_back(tri.transform(matrix));
        }
    }
}

void Scene::cleanup() {
    this->meshes.clear();
    this->trisProjected.clear();
    this->trisTransformed.clear();
}

void Scene::pushMesh(Mesh m) {
    this->meshes.push_back(m);
}
