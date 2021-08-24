//
// Created by roagen on 22.08.2021.
//

#include "TestScene.h"

TestScene::TestScene() {
    //pushing meshes
    auto ob = Mesh::loadFromObj("../assets/mesh/WC.obj");
    auto ob2 = Mesh::loadFromObj("../assets/mesh/mountains.obj");
//    this->pushMesh(ob);

    this->pushMesh(Mesh::getUnitCubeTextured());
//    this->pushMesh(ob2);
}

void TestScene::updateProperties(std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta) {
    const double LOOKSENS = 0.002;
    const double MOVESPEED = 0.5;

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
            this->camera.pos += {0,-1,0};
        }
        if(key == sf::Keyboard::LShift){
            this->camera.pos += {0,1,0};
        }

    }
    this->camera.pitch = std::max(-2.8,std::min(2.8, this->camera.pitch));
    this->camera.yaw -= mouseDelta.x * LOOKSENS;
    this->camera.pitch -= mouseDelta.y * LOOKSENS;
//    std::cout << this->camera.yaw << " " << this->camera.pitch << std::endl;
    this->theta += 0.01;
//    this->meshes[0].localTransform = Matrix::getRotationMatrixAxisX(this->theta) * Matrix::getRotationMatrixAxisZ(this->theta) * Matrix::getTranslationMarix({0,0,1});
//    this->meshes[1].localTransform = Matrix::getRotationMatrixAxisX(this->theta * 3)*Matrix::getTranslationMarix({3,0,0});
//    this->meshes[2].localTransform = Matrix::getRotationMatrixAxisZ(3.14) * Matrix::getScaleMatrix({3,3,3});
}




