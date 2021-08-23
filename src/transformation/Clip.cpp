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
    sf::Vector3<double>* insideTex[3];
    sf::Vector3<double>* outsideTex[3];

    int insidePointsCount = 0;
    int outsidePointsCount = 0;
    int insideTexCount = 0;
    int outsideTexCount = 0;


    float d0 = dist(inTri.v[0]);
    float d1 = dist(inTri.v[1]);
    float d2 = dist(inTri.v[2]);

    if(d0 >= 0) {
        insidePoints[insidePointsCount++] = &inTri.v[0];
        insideTex[insideTexCount++] = &inTri.q[0];
    } else {
        outsidePoints[outsidePointsCount++] = &inTri.v[0];
        outsideTex[outsideTexCount++] = &inTri.q[0];
    }
    if(d1 >= 0) {
        insidePoints[insidePointsCount++] = &inTri.v[1];
        insideTex[insideTexCount++] = &inTri.q[1];
    } else {
        outsidePoints[outsidePointsCount++] = &inTri.v[1];
        outsideTex[outsideTexCount++] = &inTri.q[1];
    }
    if(d2 >= 0) {
        insidePoints[insidePointsCount++] = &inTri.v[2];
        insideTex[insideTexCount++] = &inTri.q[2];
    } else {
        outsidePoints[outsidePointsCount++] = &inTri.v[2];
        outsideTex[outsideTexCount++] = &inTri.q[2];
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
        float t;




        this->triangles[0].v[0] = *insidePoints[0];
        this->triangles[0].q[0] = *insideTex[0];

        this->triangles[0].v[1] = VectorUtils::intersectPlane(planeP,planeN, *insidePoints[0], *outsidePoints[0],t);
        this->triangles[0].q[1].x = t * (outsideTex[0]->x - insideTex[0]->x) + insideTex[0]->x;
        this->triangles[0].q[1].y = t * (outsideTex[0]->y - insideTex[0]->y) + insideTex[0]->y;
        this->triangles[0].q[2].z = t * (outsideTex[0]->z - insideTex[0]->z) + insideTex[0]->z;

        this->triangles[0].v[2] = VectorUtils::intersectPlane(planeP,planeN, *insidePoints[0], *outsidePoints[1],t);
        this->triangles[0].q[2].x = t * (outsideTex[1]->x - insideTex[0]->x) + insideTex[0]->x;
        this->triangles[0].q[2].y = t * (outsideTex[1]->y - insideTex[0]->y) + insideTex[0]->y;
        this->triangles[0].q[2].z = t * (outsideTex[1]->z - insideTex[0]->z) + insideTex[0]->z;

        this->amount = 1;
        return;
    }

    if(insidePointsCount == 2 && outsidePointsCount == 1){
        float t;
        this->triangles[0].v[0] = *insidePoints[0];
        this->triangles[0].q[0] = *insideTex[0];

        this->triangles[0].v[1] = *insidePoints[1];
        this->triangles[0].q[1] = *insideTex[1];

        this->triangles[0].v[2] = VectorUtils::intersectPlane(planeP,planeN, *insidePoints[0], *outsidePoints[0],t);
        this->triangles[0].q[2].x = t * (outsideTex[0]->x - insideTex[0]->x) + insideTex[0]->x;
        this->triangles[0].q[2].y = t * (outsideTex[0]->y - insideTex[0]->y) + insideTex[0]->y;
        this->triangles[0].q[2].z = t * (outsideTex[0]->z - insideTex[0]->z) + insideTex[0]->z;


        this->triangles[1].v[0] = *insidePoints[1];
        this->triangles[1].q[0] = *insideTex[1];

        this->triangles[1].v[1] = this->triangles[0].v[2];
        this->triangles[1].q[1] = this->triangles[0].q[2];

        this->triangles[1].v[2] = VectorUtils::intersectPlane(planeP,planeN, *insidePoints[1], *outsidePoints[0],t);
        this->triangles[1].q[2].x = t * (outsideTex[0]->x - insideTex[1]->x) + insideTex[1]->x;
        this->triangles[1].q[2].y = t * (outsideTex[0]->y - insideTex[1]->y) + insideTex[1]->y;
        this->triangles[1].q[2].z = t * (outsideTex[0]->z - insideTex[1]->z) + insideTex[1]->z;

        this->amount = 2;
        return;

    }


}

// auto clipped = Clip();
// clipped.clip({}{);
//clipped.triangles.....