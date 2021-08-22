//
// Created by roagen on 22.08.2021.
//

#include "TestScene.h"

TestScene::TestScene() {
    //pushing meshes
    auto ob = Mesh::loadFromObj("../assets/mesh/WC.obj");

    this->pushMesh(ob);
    this->pushMesh(Mesh::getUnitCube());
}

void TestScene::updateProperties(std::vector<sf::Keyboard::Key> keysPressed) {


    for(auto key : keysPressed){
        if(key == sf::Keyboard::A){
            this->theta += 0.01;
        }
        if(key == sf::Keyboard::D){
            this->theta -= 0.01;
        }
    }



    this->meshes[0].localTransform = Matrix::getRotationMatrixAxisX(this->theta) * Matrix::getRotationMatrixAxisZ(this->theta) * Matrix::getTranslationMarix({0,0,1});
    this->meshes[1].localTransform = Matrix::getRotationMatrixAxisX(this->theta * 3)*Matrix::getTranslationMarix({3,0,0});
}




