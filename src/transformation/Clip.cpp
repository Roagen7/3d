//
// Created by roagen on 23.08.2021.
//

#include "Clip.h"

void Clip::clip(sf::Vector3<double> planeP, sf::Vector3<double> planeN, Triangle inTri) {
    planeN = VectorUtils::normalize(planeN);
    auto dist = [&](sf::Vector3<double> point){
        sf::Vector3<double> n = VectorUtils::normalize(point);
        return (planeN.x * point.x + planeN.y * point.y + planeN.z * point.z - VectorUtils::dot(planeN,planeP));
    };

    sf::Vector3<double>* insidePoints[3];
    sf::Vector3<double>* outsidePoints[3];
    int insidePointsCount = 0;
    int outsidePointsCount = 0;

    float d0 = dist(inTri.v[0]);
    float d1 = dist(inTri.v[1]);
    float d2 = dist(inTri.v[2]);

    if(d0 >= 0) {
        insidePoints[insidePointsCount++] = &inTri.v[0];
    } else {
        outsidePoints[outsidePointsCount++] = &inTri.v[0];
    }
    if(d1 >= 0) {
        insidePoints[insidePointsCount++] = &inTri.v[1];
    } else {
        outsidePoints[outsidePointsCount++] = &inTri.v[1];
    }
    if(d2 >= 0) {
        insidePoints[insidePointsCount++] = &inTri.v[2];
    } else {
        outsidePoints[outsidePointsCount++] = &inTri.v[2];
    }

    if(insidePointsCount == 0){
        this->amount = 0;
        return;
    }
    if(insidePointsCount == 3){
        this->triangles[0] = inTri;
        this->amount = 1;
        return;
    }
        /// LUMINOSITY !!!
    if(insidePointsCount == 1 && outsidePointsCount == 2){

        this->triangles[0].v[0] = *insidePoints[0];
        this->triangles[0].v[1] = VectorUtils::intersectPlane(planeP,planeN, *insidePoints[0], *outsidePoints[0]);
        this->triangles[0].v[2] = VectorUtils::intersectPlane(planeP,planeN, *insidePoints[0], *outsidePoints[1]);
        this->amount = 1;
        return;
    }

    if(insidePointsCount == 2 && outsidePointsCount == 1){
        this->triangles[0].v[0] = *insidePoints[0];
        this->triangles[0].v[1] = *insidePoints[1];
        this->triangles[0].v[2] = VectorUtils::intersectPlane(planeP,planeN, *insidePoints[0], *outsidePoints[0]);

        this->triangles[1].v[0] = *insidePoints[1];
        this->triangles[1].v[1] = this->triangles[0].v[2];
        this->triangles[1].v[2] = VectorUtils::intersectPlane(planeP,planeN, *insidePoints[1], *outsidePoints[0]);
        
        this->amount = 2;
        return;

    }


}

// auto clipped = Clip();
// clipped.clip({}{);
//clipped.triangles.....