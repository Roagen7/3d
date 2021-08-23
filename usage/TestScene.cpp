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

//    std::cout << "dir: "<<this->camera.lookDir().x << " " << this->camera.lookDir().y << " " << this->camera.lookDir().z << std::endl;
//    std::cout << "pos: "<<this->camera.pos.x << " " << this->camera.pos.y << " " << this->camera.pos.z << std::endl;
    for(auto key : keysPressed){
        if(key == sf::Keyboard::A){
            this->theta += 0.01;
            this->camera.pos += Matrix::getRotationMatrixAxisY(1.63).multiplyByVector(this->camera.lookDir());
        }
        if(key == sf::Keyboard::D){
            this->camera.pos -= Matrix::getRotationMatrixAxisY(1.63).multiplyByVector(this->camera.lookDir());
            this->theta -= 0.01;
        }
        if(key == sf::Keyboard::W){
            this->camera.pos += this->camera.lookDir();
//            this->camera.pos += {0,0,1};
        }
        if(key == sf::Keyboard::S){
            this->camera.pos -= this->camera.lookDir();
//            this->camera.pos -= {0,0,1};
        }
        if(key == sf::Keyboard::Right){
            this->camera.yaw -= 0.1;

        }
        if(key == sf::Keyboard::Left){
            this->camera.yaw += 0.1;

        }
        if(key == sf::Keyboard::Space){
            this->camera.pos += {0,-1,0};
        }
        if(key == sf::Keyboard::LShift){
            this->camera.pos += {0,1,0};
        }
//        if(key == sf::Keyboard::Up){
//            this->camera.pitch += 0.2;
//        }
//        if(key == sf::Keyboard::Down){
//            this->camera.pitch -= 0.2;
//        }
    }
    this->theta += 0.01;
    this->meshes[0].localTransform = Matrix::getRotationMatrixAxisX(this->theta) * Matrix::getRotationMatrixAxisZ(this->theta) * Matrix::getTranslationMarix({0,0,1});
    this->meshes[1].localTransform = Matrix::getRotationMatrixAxisX(this->theta * 3)*Matrix::getTranslationMarix({3,0,0});
}




