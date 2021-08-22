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
    void updateProperties(std::vector<sf::Keyboard::Key> keysPressed) override;

};


#endif //UNTITLED3_TESTSCENE_H
