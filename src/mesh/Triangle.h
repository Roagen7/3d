//
// Created by roagen on 21.08.2021.
//

#ifndef UNTITLED3_TRIANGLE_H
#define UNTITLED3_TRIANGLE_H

#include <SFML/System/Vector3.hpp>
#include <tuple>
#include "../transformation/Matrix.h"

class Triangle {
public:
    sf::Vector3<double> v[3];
    double lum = 0;
    Triangle(sf::Vector3<double> f, sf::Vector3<double> s, sf::Vector3<double> t);

    Triangle fixed(sf::VideoMode windowSize);
    Triangle transform(Matrix m);

    sf::Vector3<double> normal();
    Triangle();
};


#endif //UNTITLED3_TRIANGLE_H
