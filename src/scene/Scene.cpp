//
// Created by roagen on 21.08.2021.
//

#include "Scene.h"
#include "../transformation/Clip.h"

void Scene::buildFrame(Matrix globalTransformMatrix, Matrix projectionMatrix) {

//    this->updateProperties();
    this->localTransform();
    this->globalTransform(globalTransformMatrix);
    this->applyLight();
    //    this->viewSpace();
    this->project(projectionMatrix);
    this->painterSort();

}

void Scene::project(Matrix matrix) {
    //TODO: refactor into two functions
    auto view = Matrix::getViewMatrix(
            this->camera.pos,
            {0,0,1},
            {0,1,0},
            {this->camera.pitch,this->camera.yaw, this->camera.roll});


    for(auto tri : this->trisGloballyTransformed){

            Triangle triView = tri.transform(view);

            auto clipped = Clip();
            clipped.clip({0.0,0.0,0.1}, {0.0,0.0, 1.0}, triView);

            for(int i = 0; i < clipped.amount; i++){

                double w0,w1,w2;
                Triangle triClipped = clipped.triangles[i];
                Triangle triProj = triClipped.transform(matrix);

//                Triangle triProj = triClipped.transformHomog(matrix, w0,w1,w2);
//                triProj.lum = tri.lum;
//                triProj.q[0] /=  w0;
////                triProj.q[0].z = 1 / w0;
//
//                triProj.q[1] /= w1;
////                triProj.q[1].z = 1 / w1;
//                std::cout << triProj.q[0].z << " " << triProj.q[1].z << triProj.q[2].z << std::endl;
//                triProj.q[2] /= w2;
//                triProj.q[2].z = 1 / w2;

                triProj.v[0] += sf::Vector3(1.0,1.0,0.0);
                triProj.v[1] += sf::Vector3(1.0,1.0,0.0);
                triProj.v[2] += sf::Vector3(1.0,1.0,0.0);
                triProj.v[0] *= 400.0;
                triProj.v[1] *= 400.0;
                triProj.v[2] *= 400.0;
                this->trisProjected.push_back(triProj);
            }
    }
}


void Scene::localTransform() {
    for(const auto& m : this->meshes){
        for(auto tri : m.getTriangles()){
            tri = tri.transform(m.localTransform);
            tri.material = m.material;
//            std::cout << m.material->texture.getSize().x << std::endl;
            this->trisLocallyTransformed.push_back(tri);
        }
    }
}

void Scene::globalTransform(Matrix matrix) {


        for(auto tri : this->trisLocallyTransformed){
            tri = tri.transform(matrix);
            auto ray = tri.v[1] - this->camera.pos;
//
            if(VectorUtils::dot(tri.normal(), ray) >= 0.0){
                continue;
            }

            this->trisGloballyTransformed.push_back(tri);
        }

}

void Scene::cleanup() {

    this->trisProjected.clear();
    this->trisLocallyTransformed.clear();
    this->trisGloballyTransformed.clear();
}

void Scene::pushMesh(const Mesh& m) {
    this->meshes.push_back(m);
}

std::vector<Triangle> Scene::getBuiltTris() {

    return this->trisProjected;
}

void Scene::applyLight() {

    //TODO: add light sources
    sf::Vector3<double> lightDir(0.0, -1.0, -1.0);
//    sf::Vector3<double> lightDir = (  Matrix::getRotationMatrixAxisX(camera.pitch)).multiplyByVector({0,0,-1});
//    auto lightDir = -camera.lookDir();

//    std::cout << camera.lookDir().x <<  " " <<camera.lookDir().y << " "<<camera.lookDir().z<< std::endl;
//
//    std::cout << this->camera.yaw << std::endl;
    lightDir = VectorUtils::normalize(lightDir);

    for(auto& tri : this->trisGloballyTransformed){
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

void Scene::updateProperties(std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta) {

}
