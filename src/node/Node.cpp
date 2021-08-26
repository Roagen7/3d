//
// Created by roagen on 26.08.2021.
//

#include "Node.h"

Node::Node(Mesh *mesh, Collider *collider) {
    this->mesh = mesh;
    this->collider = collider;
}

Node::Node() {
    this->mesh = nullptr;
    this->collider = nullptr;
}

void Node::setTranslation(sf::Vector3<double> v) {
//    this->mesh->localTransform
    this->mesh->localTransform = Matrix::getTranslationMarix(v);

    if(this->sphCollider != nullptr){
        this->sphCollider->translation = v;
    }

}

Node::Node(Mesh *mesh, SphereCollider *sphCollider) {
    this->mesh = mesh;
    this->sphCollider = sphCollider;
}
