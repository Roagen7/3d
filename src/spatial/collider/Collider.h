//
// Created by roagen on 22.08.2021.
//

#ifndef UNTITLED3_COLLIDER_H
#define UNTITLED3_COLLIDER_H


#include <SFML/System/Vector3.hpp>
#include <string>
#include <vector>

class Collider {

public:
    static const std::string BaseName;
    static const std::string SphereName;
    static const std::string AABBName;

    int id;
    std::string name;
    explicit Collider(int id);


    virtual sf::Vector3<double> collide(std::vector<Collider> colliders);



};


#endif //UNTITLED3_COLLIDER_H
