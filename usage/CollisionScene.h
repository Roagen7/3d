//
// Created by roagen on 26.08.2021.
//

#ifndef UNTITLED3_COLLISIONSCENE_H
#define UNTITLED3_COLLISIONSCENE_H


#include "../src/scene/Scene.h"
#include "../src/node/Node.h"
class BallNode : public Node {
public:
    sf::Vector3<double> position = {0,0,0};
    sf::Vector3<double> velocity = {0,0,0};
    BallNode(Mesh* mesh, SphereCollider* collider) : Node(mesh, collider) {};
};


class CollisionScene : public Scene {
public:
    std::vector<BallNode> balls;
    CollisionScene();
    void initMaterials();
    void initObjects();
    void updateProperties(std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta) override;

};


#endif //UNTITLED3_COLLISIONSCENE_H
