//
// Created by roagen on 25.08.2021.
//

#include "GravityScene.h"
//
// Created by roagen on 22.08.2021.
//

#include "TestScene.h"



GravityScene::GravityScene() : Scene() {
    //pushing meshes
//    auto ob = Mesh::loadFromObj("../assets/mesh/WC.obj");
//    auto ob2 = Mesh::loadFromObj("../assets/mesh/mountains.obj");

    this->initMaterials();
    this->initObjects();
    auto pla1 = planet(&this->meshes[0]);
    auto pla2 = planet(&this->meshes[1]);
    auto pla3 = planet(&this->meshes[2]);
    pla1.translation = {0,5,0};
    pla1.velocity = {0,0,0.2};

    pla2.translation = {10,0,0};
    pla2.rotationPhase = 0.6;
    pla2.velocity = {0,0,0.1};
    pla3.translation = {0,0,0};
    pla3.rotationPhase = 1.6;
    pla3.radiusScale = 3.0;
    pla3.mass = 100.0;

    this->planets.push_back(pla1);
    this->planets.push_back(pla2);
    this->planets.push_back(pla3);


}




void GravityScene::updateProperties(std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta) {
    //character movement

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
    // END

    //TRANSFORMATIONS

    this->theta += 0.01;
//    this->meshes[0].localTransform =  this->meshes[0].localTransform * Matrix::getScaleMatrix({0.1,0.1,0.1});
//    this->planets[0].velocity *= 10.0;
    for(int i = 0; i < N; i++){
        auto rsc = this->planets[i].radiusScale;

        this->meshes[i].localTransform = Matrix::getRotationMatrixAxisX(this->theta) * Matrix::getTranslationMarix(this->planets[i].translation) * Matrix::getScaleMatrix({rsc,rsc,rsc});
        this->planets[i].translation += this->planets[i].velocity / rsc;
    }
    this->updatePlanets();

//    this->meshes[2].localTransform = Matrix::getRotationMatrixAxisZ(3.14);

    // END
}

void GravityScene::initMaterials() {
    auto mat = Material();
    mat.getTextureFromFile("../assets/texture/box.jpg");

    auto mat2 = Material();
    mat2.getTextureFromFile("../assets/texture/Hurricos.png");

    auto mat3 = Material();
    mat3.getTextureFromFile("../assets/texture/hammer.jpg");

    auto mat4 = Material();
    mat4.getTextureFromFile("../assets/texture/moon.jpg");

    auto mat5 = Material();
    mat5.getTextureFromFile("../assets/texture/erth.jpg");

    this->materials.push_back(mat);
    this->materials.push_back(mat2);
    this->materials.push_back(mat3);
    this->materials.push_back(mat4);
    this->materials.push_back(mat5);

}

void GravityScene::initObjects() {

    this->lights.push_back(Light({0,-1,-1}, 5, {255,255,255}));

    auto spaceship = Mesh::loadFromObj("../assets/mesh/sphere.obj", true);
    spaceship.material = &this->materials[3];
    this->pushMesh(spaceship);

    auto moon = Mesh::loadFromObj("../assets/mesh/sphere.obj", true);
    moon.material = &this->materials[4];
    this->pushMesh(moon);

    auto earth = Mesh::loadFromObj("../assets/mesh/sphere.obj", true);
    earth.material = &this->materials[5];
    this->pushMesh(earth);

}

void GravityScene::updatePlanets() {
    const float G = 0.0001;



    for(int i =0 ; i < N ; i++){
        for(int j = i + 1; j < N; j++){
            auto &p1 = this->planets[i];
            auto &p2 = this->planets[j];
            auto r21 = p2.translation - p1.translation;

//            std::cout << r21.x <<" " << r21.y << " "<< r21.z << std::endl;
            if(r21 != sf::Vector3<double>(0,0,0)){
                auto r21Len = std::sqrt(VectorUtils::dot(r21,r21));
                auto coeff = G * p1.mass * p2.mass / (r21Len * r21Len);
                p1.velocity += coeff * r21 / p1.mass;
                p2.velocity -= coeff * r21 / p2.mass;

            }




        }
    }
}




