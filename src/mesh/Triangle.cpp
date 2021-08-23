//
// Created by roagen on 21.08.2021.
//

#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include "Triangle.h"
#include "../transformation/VectorUtils.h"


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
    tri.lum = this->lum;
    tri.q[0] = this->q[0];
    tri.q[1] = this->q[1];
    tri.q[2] = this->q[2];


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
    Triangle transformed = {m.multiplyByVector(this->v[0]), m.multiplyByVector(this->v[1]),m.multiplyByVector(this->v[2])};
    transformed.q[0] = this->q[0];
    transformed.q[1] = this->q[1];
    transformed.q[2] = this->q[2];
    transformed.lum = this->lum;
    return transformed;
}

sf::Vector3<double> Triangle::normal() {

    auto line1 = this->v[1] - this->v[0];
    auto line2 = this->v[2] - this->v[0];
    auto normal = VectorUtils::normalize(VectorUtils::cross(line1, line2));
    return normal;
}

Triangle::Triangle(sf::Vector3<double> f, sf::Vector3<double> s, sf::Vector3<double> t, sf::Vector2<double> t1, sf::Vector2<double> t2, sf::Vector2<double> t3) {
    this->v[0] = f;
    this->v[1] = s;
    this->v[2] = t;
    this->q[0].x = t1.x;
    this->q[0].y = t1.y;
    this->q[0].z = 1;
    this->q[1].x = t2.x;
    this->q[1].y = t2.y;
    this->q[1].z = 1;
    this->q[2].x = t3.x;
    this->q[2].y = t3.y;
    this->q[2].z = 1;
}

