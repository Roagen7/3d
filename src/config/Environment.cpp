//
// Created by roagen on 28.08.2021.
//

#include "Environment.h"

Environment Environment::config(bool drawMaterials, sf::Color bgColor, double bgColorEnergy) {
    auto env = Environment();
    env.drawMaterials = drawMaterials;
    env.bgColor = bgColor;
    env.bgColorEnergy = bgColorEnergy;
    return env;
}
