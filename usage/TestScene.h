//
// Created by roagen on 22.08.2021.
//

#ifndef UNTITLED3_TESTSCENE_H
#define UNTITLED3_TESTSCENE_H


#include "../src/scene/Scene.h"

class TestScene : public Scene {
public:
    float theta = 0;
    explicit TestScene();
    void updateProperties(double timeDelta, std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta) override;
    void initMaterials();
    void initObjects();

};


#endif //UNTITLED3_TESTSCENE_H
