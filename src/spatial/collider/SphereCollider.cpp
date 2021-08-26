//
// Created by roagen on 22.08.2021.
//

#include "SphereCollider.h"

SphereCollider::SphereCollider(int id,sf::Vector3<double> translation, double radius) : Collider(id) {
    this->name = Collider::SphereName;
    this->translation = translation;
    this->radius = radius;
}

sf::Vector3<double> SphereCollider::collide(std::vector<Collider> colliders) {
    for(auto c : colliders){




    }

}
