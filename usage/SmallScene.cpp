//
// Created by roagen on 22.08.2021.
//

#include "SmallScene.h"

SmallScene::SmallScene() : Scene() {
    this->initMaterials();
    this->initObjects();
}

void SmallScene::updateProperties(std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta) {
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
//    this->meshes[0].localTransform = Matrix::getRotationMatrixAxisY(this->theta) * Matrix::getRotationMatrixAxisZ(this->theta);
    this->meshes[0].localTransform = Matrix::getRotationMatrixAxisZ(3.14) * Matrix::getScaleMatrix({5,5,5});
}

void SmallScene::initMaterials() {
    auto mat = Material();
    mat.getTextureFromFile("../assets/texture/moon.jpg");
    mat.specular = 10.0;

    this->materials.push_back(mat);


}

void SmallScene::initObjects() {
    auto cube = Mesh::getUnitCubeTextured();
    auto statue = Mesh::loadFromObj("../assets/mesh/stat.obj",true);

    statue.material = &this->materials[1];
    cube.material = &this->materials[1];

//    this->pushMesh(cube);
    this->pushMesh(statue);

    auto l = Light({0.0,-1.0,-1.0}, 2.0, {255,255,255});
//    auto l2 = Light({0,-1,0}, 0.5, {255,255,0});
    this->lights.push_back(l);
//    this->lights.push_back(l2);

}




