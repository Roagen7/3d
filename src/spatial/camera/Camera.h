//
// Created by roagen on 22.08.2021.
//

#ifndef UNTITLED3_CAMERA_H
#define UNTITLED3_CAMERA_H

#include <SFML/System/Vector3.hpp>
#include "../../transformation/Matrix.h"

class Camera {
public:
    sf::Vector3<double> pos;
    double yaw, pitch, roll;
    Camera();

    sf::Vector3<double> lookDir();

};

#endif //UNTITLED3_CAMERA_H
