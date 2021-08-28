//
// Created by roagen on 28.08.2021.
//

#ifndef UNTITLED3_REFLECTION_H
#define UNTITLED3_REFLECTION_H


#include <SFML/Graphics/Color.hpp>

class Reflection {
public:
    sf::Color color;
    double lum;

    Reflection(const sf::Color &color, double lum);

};


#endif //UNTITLED3_REFLECTION_H
