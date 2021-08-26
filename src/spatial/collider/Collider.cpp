//
// Created by roagen on 22.08.2021.
//

#include "Collider.h"

#include <utility>
#include <iostream>

const std::string Collider::BaseName = "Base collider";
const std::string Collider::SphereName = "Sphere collider";
const std::string Collider::AABBName = "AABB collider";


sf::Vector3<double> Collider::collide(std::vector<Collider> colliders) {

    return {};
}

Collider::Collider(int id, std::string name) {
    this->id = id;
    this->name = std::move(name);
    this->translation = {0,0,0};
}
