//
// Created by roagen on 21.08.2021.
//

#ifndef UNTITLED3_MATRIX_H
#define UNTITLED3_MATRIX_H
#include <cmath>
#include <SFML/Window.hpp>
#include "VectorUtils.h"

class Matrix {
public:
    float m[4][4] = { 0 };
    sf::Vector3<double> multiplyByVector(sf::Vector3<double> v);
    sf::Vector3<double> multiplyByVectorHomog(sf::Vector3<double> v, double& w);

    Matrix getInverse();
    static Matrix getProjectionMatrix(sf::Vector2u screenSize);
    static Matrix getRotationMatrixAxisX(double rad);
    static Matrix getRotationMatrixAxisZ(double rad);
    static Matrix getRotationMatrixAxisY(double rad);
    static Matrix getTranslationMarix(sf::Vector3<double> translation);
    static Matrix getScaleMatrix(sf::Vector3<double> scale);
    static Matrix getViewMatrix(sf::Vector3<double> cameraPos, sf::Vector3<double> target, sf::Vector3<double> up, sf::Vector3<double> rotation);
    static Matrix getPointAt(sf::Vector3<double> camera, sf::Vector3<double> target, sf::Vector3<double> up);
    static Matrix getIdentityMatrix();
    friend Matrix operator*(Matrix m1, Matrix m2);



};


#endif //UNTITLED3_MATRIX_H
