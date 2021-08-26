//
// Created by roagen on 22.08.2021.
//

#include "Collider.h"

const std::string Collider::BaseName = "Base collider";
const std::string Collider::SphereName = "Sphere collider";
const std::string Collider::AABBName = "AABB collider";


sf::Vector3<double> Collider::collide(std::vector<Collider> colliders) {
    return {};
}

Collider::Collider(int id) {
    this->id = id;
    this->name = Collider::BaseName;
}
