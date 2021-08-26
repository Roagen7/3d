//
// Created by roagen on 22.08.2021.
//

#include <iostream>
#include "SphereCollider.h"
#include "../../transformation/VectorUtils.h"

SphereCollider::SphereCollider(int id,sf::Vector3<double> translation, double radius) : Collider(id, Collider::SphereName) {

    this->translation = translation;
    this->radius = radius;
}


SphereCollider::SphereCollider(int id): Collider(id, Collider::SphereName) {
    this->translation = {0,0,0};
    this->radius = 0;
}


sf::Vector3<double> SphereCollider::collide(std::vector<SphereCollider> sphereColliders) {

    for(auto col : sphereColliders){
        if(col.id != this->id){

            sf::Vector3<double> d = col.translation - this->translation;
            double dLenSq = VectorUtils::dot(d,d);
            double rSumSq= (col.radius + this->radius) * (col.radius + this->radius);
            std::cout << rSumSq << std::endl;
            if(dLenSq < rSumSq){
                std::cout << "ttttt" << std::endl;
            }

        }
    }


    return {};
}
