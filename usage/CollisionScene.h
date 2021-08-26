//
// Created by roagen on 26.08.2021.
//

#ifndef UNTITLED3_COLLISIONSCENE_H
#define UNTITLED3_COLLISIONSCENE_H


#include "../src/scene/Scene.h"

class CollisionScene : public Scene {
public:
    CollisionScene();
    void initMaterials();
    void initObjects();
    void updateProperties(std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta) override;

};


#endif //UNTITLED3_COLLISIONSCENE_H
