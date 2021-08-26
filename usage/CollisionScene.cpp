//
// Created by roagen on 26.08.2021.
//

#include "CollisionScene.h"
#include "../src/spatial/collider/SphereCollider.h"








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
    auto col1 = SphereCollider(0);
    col1.radius = 1;
    auto col2 = SphereCollider(1);
    col2.radius = 1;

    this->pushMesh(sph1);
    this->pushSphereCollider(col1);
    this->pushMesh(sph2);
    this->pushSphereCollider(col2);

    auto n1 = BallNode(&this->meshes[0], &this->sphereColliders[0]);
    auto n2 = BallNode(&this->meshes[1], &this->sphereColliders[1]);

    n1.position = {0,0,5};
    n2.position = {10,0,0};

    n1.setTranslation(n1.position);
    n1.velocity = {0,0,-0.02};

    n2.setTranslation(n2.position);
    n2.velocity = {-0.04,0,0};

    this->balls.push_back(n1);
    this->balls.push_back(n2);

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


    for(auto &n : this->balls){

        n.position += n.velocity;
        n.setTranslation(n.position);
    }

    for(int i = 0; i < this->balls.size(); i++){
        for(int j = i + 1; j < this->balls.size(); j++){
            auto& n1 = this->balls[i];
            auto& n2 = this->balls[j];

            if(SphereCollider::checkCollision(*n1.sphCollider,*n2.sphCollider)){
                

            }
        }
    }




}

