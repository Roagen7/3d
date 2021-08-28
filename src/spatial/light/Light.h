//
// Created by roagen on 22.08.2021.
//

#ifndef UNTITLED3_LIGHT_H
#define UNTITLED3_LIGHT_H


#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Color.hpp>

class Light {
private:
    // [0,1]
    sf::Vector3<double> direction;
public:
    Light(const sf::Vector3<double> &direction, double energy, const sf::Color &color);


public:
    double energy = 0;
    sf::Color color;
    [[nodiscard]] sf::Vector3<double> getDirection() const;
};


#endif //UNTITLED3_LIGHT_H
