//
// Created by roagen on 22.08.2021.
//

#include "TestScene.h"

TestScene::TestScene() {
    //pushing meshes
    auto ob = Mesh::loadFromObj("../assets/mesh/WC.obj");
    auto ob2 = Mesh::loadFromObj("../assets/mesh/mountains.obj");
    auto ob3 = Mesh::getUnitCubeTextured();
//    this->pushMesh(ob);
    auto mat = Material();
    mat.getTextureFromFile("../assets/texture/box.jpg");
    //KEEP PROPER ORDER materials -> meshes
    // init materials

    this->materials.push_back(mat);
    this->materials.push_back(Material::defaultMaterial());
    //add materials to meshes

//
    ob3.material = &this->materials[0];

    this->pushMesh(ob3);

    ob2.material = &this->materials[1];
    this->pushMesh(ob2);
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

    this->theta += 0.01;

    this->meshes[0].localTransform = Matrix::getRotationMatrixAxisX(this->theta) * Matrix::getRotationMatrixAxisZ(this->theta) * Matrix::getTranslationMarix({0,0,1});

}




