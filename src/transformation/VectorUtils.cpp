//
// Created by roagen on 21.08.2021.
//

#include <complex>
#include <iostream>
#include <array>
#include <memory>
#include "VectorUtils.h"

double VectorUtils::dot(sf::Vector3<double> v1, sf::Vector3<double> v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

sf::Vector3<double> VectorUtils::cross(sf::Vector3<double> v1, sf::Vector3<double> v2) {
    sf::Vector3<double> v;
    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.x;

    return v;
}

sf::Vector3<double> VectorUtils::normalize(sf::Vector3<double> v){
    return v / std::sqrt(dot(v,v));
}

sf::Vector3<double>
VectorUtils::intersectPlane(sf::Vector3<double> planeP, sf::Vector3<double> planeN, sf::Vector3<double> lineStart,
                            sf::Vector3<double> lineEnd) {
    planeN = VectorUtils::normalize(planeN);
    float planeD = -VectorUtils::dot(planeN,planeP);
    float ad = VectorUtils::dot(lineStart,planeN);
    float bd = VectorUtils::dot(lineEnd, planeN);
    float t = (-planeD - ad) / (bd - ad);
    sf::Vector3<double> lineStartToEnd = lineEnd - lineStart;
    sf::Vector3<double> lineToIntersect = lineStartToEnd * (double) t;
    return lineStart + lineToIntersect;
}


//std::string VectorUtils::exec(const char* cmd) {
//    std::array<char, 128> buffer;
//    std::string result;
//    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
//    if (!pipe) {
//        throw std::runtime_error("popen() failed!");
//    }
//    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
//        result += buffer.data();
//    }
//    return result;
//}
