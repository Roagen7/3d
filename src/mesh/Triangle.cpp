//
// Created by roagen on 21.08.2021.
//

#include <SFML/Window/VideoMode.hpp>
#include "Triangle.h"


Triangle::Triangle(sf::Vector3<double> f, sf::Vector3<double> s, sf::Vector3<double> t) {
    this->v[0] = f;
    this->v[1] = s;
    this->v[2] = t;
}


Triangle::Triangle() {
    this->v[0] = sf::Vector3<double>(0,0,0);
    this->v[1] = sf::Vector3<double>(0,0,0);
    this->v[2] = sf::Vector3<double>(0,0,0);
}

Triangle Triangle::fixed(sf::VideoMode windowSize) {

    Triangle tri;
    tri.v[0].x = -1.0 + 2.0 *   this->v[0].x / windowSize.width;
    tri.v[0].y = 1.0 - 2.0 *  this->v[0].y / windowSize.width;
    tri.v[0].z = 1.0 - 2.0 *  this->v[0].z / windowSize.width;
    tri.v[1].x = -1.0 + 2.0 *  this->v[1].x / windowSize.width;
    tri.v[1].y = 1.0 - 2.0 *  this->v[1].y / windowSize.width;
    tri.v[1].z = 1.0 - 2.0 * this->v[1].z / windowSize.width;
    tri.v[2].x = -1.0 + 2.0 *  this->v[2].x / windowSize.width;
    tri.v[2].y = 1.0 - 2.0 *  this->v[2].y / windowSize.width;
    tri.v[2].z = 1.0 - 2.0 *  this->v[2].z / windowSize.width;

    return tri;
}

Triangle Triangle::transform(Matrix m) {
    return {m.multiplyByVector(this->v[0]), m.multiplyByVector(this->v[1]),m.multiplyByVector(this->v[2])};
}

