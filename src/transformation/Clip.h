//
// Created by roagen on 23.08.2021.
//

#ifndef UNTITLED3_CLIP_H
#define UNTITLED3_CLIP_H


#include "../mesh/Triangle.h"

class Clip {
public:
    Triangle triangles[2];
    int amount;
    void clip(sf::Vector3<double> planeP, sf::Vector3<double> planeN, Triangle inTri);






};


#endif //UNTITLED3_CLIP_H
