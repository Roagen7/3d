//
// Created by roagen on 21.08.2021.
//

#ifndef UNTITLED3_VECTORUTILS_H
#define UNTITLED3_VECTORUTILS_H


#include <SFML/System/Vector3.hpp>


class VectorUtils {
public:
//    static std::string exec(const char* cmd);
    static double dot(sf::Vector3<double> v1, sf::Vector3<double> v2);
    static sf::Vector3<double> cross(sf::Vector3<double> v1, sf::Vector3<double> v2);
    static sf::Vector3<double> normalize(sf::Vector3<double> v);
};


#endif //UNTITLED3_VECTORUTILS_H
