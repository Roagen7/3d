//
// Created by roagen on 22.08.2021.
//

#include "Camera.h"

Camera::Camera() {
    this->yaw = 0;
    this->pitch = 0;
    this->roll = 0;
    this->pos = {0,0,0};
}

sf::Vector3<double> Camera::lookDir() {
//    auto cameraRotMatrix = Matrix::getRotationMatrixAxisZ(this->roll)
//            *Matrix::getRotationMatrixAxisY(this->yaw)
//            *Matrix::getRotationMatrixAxisX(this->pitch);

    auto cameraRotMatrix = Matrix::getRotationMatrixAxisY(this->yaw);


    return cameraRotMatrix.multiplyByVector({0,0,1});

}
