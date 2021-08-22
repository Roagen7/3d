//
// Created by roagen on 22.08.2021.
//

#include "Light.h"
#include "../../transformation/VectorUtils.h"

sf::Vector3<double> Light::getDirection() const {
    return VectorUtils::normalize(direction);
}
