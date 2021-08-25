//
// Created by roagen on 22.08.2021.
//

#include "TestScene.h"

TestScene::TestScene() : Scene() {
    //pushing meshes
//    auto ob = Mesh::loadFromObj("../assets/mesh/WC.obj");
//    auto ob2 = Mesh::loadFromObj("../assets/mesh/mountains.obj");



    this->initMaterials();
    this->initObjects();


}

void TestScene::updateProperties(std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta) {
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

    this->theta += 0.01;
    this->meshes[2].localTransform = Matrix::getRotationMatrixAxisX(3.14) * Matrix::getScaleMatrix({1,1,1}) * Matrix::getTranslationMarix({0,+1000,100});
    this->meshes[0].localTransform = Matrix::getRotationMatrixAxisX(this->theta) * Matrix::getRotationMatrixAxisZ(this->theta) * Matrix::getTranslationMarix({0,0,1});
//    this->meshes[2].localTransform = Matrix::getRotationMatrixAxisZ(3.14);
    this->meshes[3].localTransform = Matrix::getRotationMatrixAxisX(6.28);

}

void TestScene::initMaterials() {
    auto mat = Material();
    mat.getTextureFromFile("../assets/texture/box.jpg");

    auto mat2 = Material();
    mat2.getTextureFromFile("../assets/texture/Hurricos.png");

    auto mat3 = Material();
    mat3.getTextureFromFile("../assets/texture/hammer.jpg");

    auto mat4 = Material();
    mat4.getTextureFromFile("../assets/texture/artisans.png");

    this->materials.push_back(mat);
    this->materials.push_back(mat2);
    this->materials.push_back(mat3);
    this->materials.push_back(mat4);

}

void TestScene::initObjects() {
    auto cube = Mesh::getUnitCubeTextured();
    auto hurricos = Mesh::loadFromObj("../assets/mesh/hurricoss.obj", true);
    auto hammer = Mesh::loadFromObj("../assets/mesh/hammars.obj", true);
    auto artisans = Mesh::loadFromObj("../assets/mesh/artisans.obj", true);
    cube.material = &this->materials[1];
    hurricos.material = &this->materials[2];
    hammer.material = &this->materials[3];
    artisans.material = &this->materials[4];

    this->pushMesh(cube);
    this->pushMesh(hammer);
    this->pushMesh(hurricos);
    this->pushMesh(artisans);
}




