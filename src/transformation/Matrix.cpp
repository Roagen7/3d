//
// Created by roagen on 21.08.2021.
//

#include "Matrix.h"

Matrix Matrix::getProjectionMatrix(sf::Vector2u screenSize) {

    auto matrix = Matrix();
    float fNear = 0.1f;
    float fFar = 1000.0f;
    float fFov = 90.0f;
    float fAspectRatio = (float)screenSize.y / (float)screenSize.x;
    float fFovRad = 1.0f / std::tan(fFov * 0.5f / 180.0f * 3.14159f);

    matrix.m[0][0] = fAspectRatio * fFovRad;
    matrix.m[1][1] = fFovRad;
    matrix.m[2][2] = fFar / (fFar - fNear);
    matrix.m[3][2] = (-fFar * fNear) / (fFar - fNear);
    matrix.m[2][3] = 1.0f;
    matrix.m[3][3] = 0.0f;
    return matrix;

}

sf::Vector3<double> Matrix::multiplyByVector(sf::Vector3<double> i) {
    sf::Vector3<double> o;
    o.x = i.x * this->m[0][0] + i.y * this->m[1][0] + i.z * this->m[2][0] + this->m[3][0];
    o.y = i.x * this->m[0][1] + i.y * this->m[1][1] + i.z * this->m[2][1] + this->m[3][1];
    o.z = i.x * this->m[0][2] + i.y * this->m[1][2] + i.z * this->m[2][2] + this->m[3][2];
    float w = i.x * this->m[0][3] + i.y * this->m[1][3] + i.z * this->m[2][3] + this->m[3][3];
    if(w != 0){
        o.x /= w;
        o.y /= w;
        o.z /= w;
        return o;
    }

    return o;
}

Matrix Matrix::getRotationMatrixAxisX(double rad) {
    auto matrix = Matrix();
    matrix.m[0][0] = 1;
    matrix.m[1][1] = cosf(rad * 0.5f);
    matrix.m[1][2] = sinf(rad * 0.5f);
    matrix.m[2][1] = -sinf(rad * 0.5f);
    matrix.m[2][2] = cosf(rad * 0.5f);
    matrix.m[3][3] = 1;
    return matrix;
}

Matrix Matrix::getRotationMatrixAxisZ(double rad) {
    auto matrix = Matrix();
    matrix.m[0][0] = cosf(rad);
    matrix.m[0][1] = sinf(rad);
    matrix.m[1][0] = -sinf(rad);
    matrix.m[1][1] = cosf(rad);
    matrix.m[2][2] = 1;
    matrix.m[3][3] = 1;
    return matrix;
}

Matrix Matrix::getRotationMatrixAxisY(double rad) {
    auto matrix = Matrix();
    matrix.m[0][0] = cosf(rad);
    matrix.m[0][2] = sinf(rad);
    matrix.m[2][0] = -sinf(rad);
    matrix.m[1][1] = 1.0f;
    matrix.m[2][2] = cosf(rad);
    matrix.m[3][3] = 1.0f;
    return matrix;
}

Matrix operator*(Matrix m1, Matrix m2) {

    Matrix matrix;
    for (int c = 0; c < 4; c++)
        for (int r = 0; r < 4; r++)
            matrix.m[r][c] = m1.m[r][0] * m2.m[0][c] + m1.m[r][1] * m2.m[1][c] + m1.m[r][2] * m2.m[2][c] + m1.m[r][3] * m2.m[3][c];
    return matrix;
}

Matrix Matrix::getTranslationMarix(sf::Vector3<double> translation) {
    Matrix matrix;
    matrix.m[0][0] = 1.0f;
    matrix.m[1][1] = 1.0f;
    matrix.m[2][2] = 1.0f;
    matrix.m[3][3] = 1.0f;
    matrix.m[3][0] = translation.x;
    matrix.m[3][1] = translation.y;
    matrix.m[3][2] = translation.z;
    return matrix;
}

Matrix Matrix::getIdentityMatrix() {
    Matrix matrix;
    matrix.m[0][0] = 1.0f;
    matrix.m[1][1] = 1.0f;
    matrix.m[2][2] = 1.0f;
    matrix.m[3][3] = 1.0f;
    return matrix;
}

Matrix Matrix::getScaleMatrix(sf::Vector3<double> scale) {
    Matrix matrix;
    matrix.m[0][0] = scale.x;
    matrix.m[1][1] = scale.y;
    matrix.m[2][2] = scale.z;
    matrix.m[3][3]  = 1.0;

    return matrix;
}

Matrix Matrix::getViewMatrix(sf::Vector3<double> cameraPos, sf::Vector3<double> target, sf::Vector3<double> up, sf::Vector3<double> rotation) {
    Matrix matrix;


    auto cameraRot = Matrix::getRotationMatrixAxisX(rotation.x)
                    *Matrix::getRotationMatrixAxisY(rotation.y)
                    *Matrix::getRotationMatrixAxisZ(rotation.z);
    auto lookDir = cameraRot.multiplyByVector(target);
    target =  cameraPos + lookDir;
    auto cameraView = Matrix::getPointAt(cameraPos,target, up);
    matrix = cameraView.getInverse();
    return matrix;
}

Matrix Matrix::getPointAt(sf::Vector3<double> camera, sf::Vector3<double> target, sf::Vector3<double> up) {
    Matrix matrix;

    sf::Vector3<double> newForward = target - camera;
    newForward = VectorUtils::normalize(newForward);

    sf::Vector3<double> a = newForward * VectorUtils::dot(up, newForward);
    sf::Vector3<double> newUp = up - a;
    newUp = VectorUtils::normalize(newUp);

    sf::Vector3<double> newRight = VectorUtils::cross(newUp, newForward);

    matrix.m[0][0] = newRight.x;	matrix.m[0][1] = newRight.y;	matrix.m[0][2] = newRight.z;	matrix.m[0][3] = 0.0f;
    matrix.m[1][0] = newUp.x;		matrix.m[1][1] = newUp.y;		matrix.m[1][2] = newUp.z;		matrix.m[1][3] = 0.0f;
    matrix.m[2][0] = newForward.x;	matrix.m[2][1] = newForward.y;	matrix.m[2][2] = newForward.z;	matrix.m[2][3] = 0.0f;
    matrix.m[3][0] = camera.x;		matrix.m[3][1] = camera.y;		matrix.m[3][2] = camera.z;		matrix.m[3][3] = 1.0f;

    return matrix;
}

Matrix Matrix::getInverse() {
    Matrix matrix;
    matrix.m[0][0] = this->m[0][0]; matrix.m[0][1] = this->m[1][0]; matrix.m[0][2] = this->m[2][0]; matrix.m[0][3] = 0.0f;
    matrix.m[1][0] = this->m[0][1]; matrix.m[1][1] = this->m[1][1]; matrix.m[1][2] = this->m[2][1]; matrix.m[1][3] = 0.0f;
    matrix.m[2][0] = this->m[0][2]; matrix.m[2][1] = this->m[1][2]; matrix.m[2][2] = this->m[2][2]; matrix.m[2][3] = 0.0f;
    matrix.m[3][0] = -(this->m[3][0] * matrix.m[0][0] + this->m[3][1] * matrix.m[1][0] + this->m[3][2] * matrix.m[2][0]);
    matrix.m[3][1] = -(this->m[3][0] * matrix.m[0][1] + this->m[3][1] * matrix.m[1][1] + this->m[3][2] * matrix.m[2][1]);
    matrix.m[3][2] = -(this->m[3][0] * matrix.m[0][2] + this->m[3][1] * matrix.m[1][2] + this->m[3][2] * matrix.m[2][2]);
    matrix.m[3][3] = 1.0;
    return matrix;
}
