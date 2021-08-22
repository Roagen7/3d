//
// Created by roagen on 21.08.2021.
//

#ifndef UNTITLED3_MATRIX_H
#define UNTITLED3_MATRIX_H
#include <cmath>
#include <SFML/Window.hpp>

class Matrix {
public:
    float m[4][4] = { 0 };
    sf::Vector3<double> multiplyByVector(sf::Vector3<double> v);
    static Matrix getProjectionMatrix(sf::Vector2u screenSize);
    static Matrix getRotationMatrixAxisX(double rad);
    static Matrix getRotationMatrixAxisZ(double rad);
    static Matrix getTranslationMarix(sf::Vector3<double> translation);

    friend Matrix operator*(Matrix m1, Matrix m2);


};


#endif //UNTITLED3_MATRIX_H
