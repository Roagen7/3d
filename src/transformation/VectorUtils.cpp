//
// Created by roagen on 21.08.2021.
//

#include "VectorUtils.h"

double VectorUtils::dot(sf::Vector3<double> v1, sf::Vector3<double> v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

sf::Vector3<double> VectorUtils::cross(sf::Vector3<double> v1, sf::Vector3<double> v2) {
    sf::Vector3<double> v;
    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.z;
    return v;
}
