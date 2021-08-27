//
// Created by roagen on 27.08.2021.
//

#ifndef UNTITLED3_SMALLSCENE_H
#define UNTITLED3_SMALLSCENE_H


#include "../src/scene/Scene.h"

class SmallScene : public Scene {
public:
    float theta = 0;
    explicit SmallScene();
    void updateProperties(std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta) override;
    void initMaterials();
    void initObjects();

};


#endif //UNTITLED3_SMALLSCENE_H
