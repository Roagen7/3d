//
// Created by roagen on 28.08.2021.
//

#ifndef UNTITLED3_ENVIRONMENT_H
#define UNTITLED3_ENVIRONMENT_H


#include <SFML/Graphics/Color.hpp>

class Environment {
public:
    bool drawMaterials;
    sf::Color bgColor;
    double bgColorEnergy;

    static Environment config(bool drawMaterials = true, sf::Color bgColor = sf::Color::Black, double bgColorEnergy = 1);


};


#endif //UNTITLED3_ENVIRONMENT_H
