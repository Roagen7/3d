//
// Created by roagen on 22.08.2021.
//

#ifndef UNTITLED3_SPHERECOLLIDER_H
#define UNTITLED3_SPHERECOLLIDER_H


#include "Collider.h"

class SphereCollider : public Collider {
public:

    double radius;

    SphereCollider(int id,sf::Vector3<double> translation, double radius);
    explicit SphereCollider(int id);
    sf::Vector3<double> collide(std::vector<SphereCollider> sphereColliders);


};


#endif //UNTITLED3_SPHERECOLLIDER_H
