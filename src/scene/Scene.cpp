//
// Created by roagen on 21.08.2021.
//

#include "Scene.h"
#include "../transformation/Clip.h"


void Scene::pushMesh(const Mesh& m) {
    this->meshes.push_back(m);
}


void Scene::pushSphereCollider(const SphereCollider &c) {
    this->sphereColliders.push_back(c);
}

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
            //transform to view space
            Triangle triView = tri.transform(view);


            //clip triangles
            auto clipped = Clip();
            clipped.clip({0.0,0.0,0.1}, {0.0,0.0, 1.0}, triView);

            for(int i = 0; i < clipped.amount; i++){

//                double w0,w1,w2;
                Triangle triClipped = clipped.triangles[i];

                //project the clipped triangles
                Triangle triProj = triClipped.transform(matrix);

                triProj.v[0] += sf::Vector3(1.0,1.0,0.0);
                triProj.v[1] += sf::Vector3(1.0,1.0,0.0);
                triProj.v[2] += sf::Vector3(1.0,1.0,0.0);

                triProj.v[0].x *= (double) this->windowSize.x / 2;
                triProj.v[0].y *= (double) this->windowSize.y / 2;
                triProj.v[1].x *= (double) this->windowSize.x / 2;
                triProj.v[1].y *= (double) this->windowSize.y / 2;
                triProj.v[2].x *= (double) this->windowSize.x / 2;
                triProj.v[2].y *= (double) this->windowSize.y / 2;

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



std::vector<Triangle> Scene::getBuiltTris() {

    return this->trisProjected;
}

void Scene::applyLight() {

    //TODO: add light sources
    sf::Vector3<double> lightDir(0.0, -1.0, -1.0);
//    sf::Vector3<double> lightDir = (  Matrix::getRotationMatrixAxisX(camera.pitch)).multiplyByVector({0,0,-1});
//    lightDir = -camera.lookDir();

//    std::cout << camera.lookDir().x <<  " " <<camera.lookDir().y << " "<<camera.lookDir().z<< std::endl;
//
//    std::cout << this->camera.yaw << std::endl;
//    lightDir = VectorUtils::normalize(lightDir);

    //lambert reflection
    for(auto& tri : this->trisGloballyTransformed){
        auto normal = tri.normal();
        auto dotNormDir = VectorUtils::dot(normal, lightDir);
    

        auto r = VectorUtils::normalize(lightDir - 2 * dotNormDir * normal);
        auto v = VectorUtils::normalize(tri.v[1] - this->camera.pos);
        auto specAlpha = 5.0;

        tri.lum = std::max(0.1,dotNormDir) * 0.9;
        tri.lum += std::pow(VectorUtils::dot(r,v), specAlpha);
//        tri.lum = 1;
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

Scene::Scene(){
    this->windowSize = {800,800};

}

