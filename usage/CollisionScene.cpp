//
// Created by roagen on 26.08.2021.
//

#include "CollisionScene.h"

CollisionScene::CollisionScene() {
    this->initMaterials();
    this->initObjects();
}


void CollisionScene::initMaterials() {
    auto m1 = Material();
    m1.getTextureFromFile("../assets/texture/moon.jpg");
    this->materials.push_back(m1);
}

void CollisionScene::initObjects() {
    auto sph1 = Mesh::loadFromObj("../assets/mesh/sphere.obj", true);
    auto sph2 = Mesh::loadFromObj("../assets/mesh/sphere.obj", true);
    sph1.material = &this->materials[1];
    sph2.material = &this->materials[1];
    this->pushMesh(sph1);
    this->pushMesh(sph2);
}

void CollisionScene::updateProperties(std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta) {
    const double LOOKSENS = 0.002;
    const double MOVESPEED = 2;

    for(auto key : keysPressed){
        if(key == sf::Keyboard::A){
            this->camera.pos += Matrix::getRotationMatrixAxisY(1.63).multiplyByVector(this->camera.lookDir() * MOVESPEED);
        }
        if(key == sf::Keyboard::D){
            this->camera.pos -= Matrix::getRotationMatrixAxisY(1.63).multiplyByVector(this->camera.lookDir() * MOVESPEED);
        }
        if(key == sf::Keyboard::W){
            this->camera.pos += this->camera.lookDir() * MOVESPEED;
        }
        if(key == sf::Keyboard::S){
            this->camera.pos -= this->camera.lookDir() * MOVESPEED;
        }
        if(key == sf::Keyboard::Space){
            this->camera.pos += {0,-MOVESPEED,0} ;
        }
        if(key == sf::Keyboard::LShift){
            this->camera.pos -= {0,-MOVESPEED,0} ;
        }

    }
    this->camera.pitch = std::max(-2.8,std::min(2.8, this->camera.pitch));
    this->camera.yaw -= mouseDelta.x * LOOKSENS;
    this->camera.pitch -= mouseDelta.y * LOOKSENS;


}

