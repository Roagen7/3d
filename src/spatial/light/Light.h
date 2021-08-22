//
// Created by roagen on 22.08.2021.
//

#ifndef UNTITLED3_LIGHT_H
#define UNTITLED3_LIGHT_H


#include <SFML/System/Vector3.hpp>

class Light {
private:
    // [0,1]
    sf::Vector3<double> direction;
public:
    double energy = 0;
    [[nodiscard]] sf::Vector3<double> getDirection() const;
};


#endif //UNTITLED3_LIGHT_H
