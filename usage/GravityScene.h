//
// Created by roagen on 25.08.2021.
//

#ifndef UNTITLED3_GRAVITYSCENE_H
#define UNTITLED3_GRAVITYSCENE_H


#include "../src/scene/Scene.h"

const int N = 3;

struct planet {
    double radiusScale = 1.0;
    double mass = 1.0;
    sf::Vector3<double> translation;
    sf::Vector3<double> velocity = {0,0,0};
    double rotationPhase = 0;

    Mesh* mesh{};
    explicit planet(Mesh* m){
        mesh = m;
    };
};



class GravityScene : public Scene{
public:
    std::vector<planet> planets;
    float theta = 0;
    explicit GravityScene();
    void updateProperties(double timeDelta,std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta) override;
    void initMaterials();
    void initObjects();
    void updatePlanets();




};


#endif //UNTITLED3_GRAVITYSCENE_H
