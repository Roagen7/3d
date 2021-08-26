//
// Created by roagen on 26.08.2021.
//

#ifndef UNTITLED3_NODE_H
#define UNTITLED3_NODE_H


#include "../mesh/Mesh.h"
#include "../spatial/collider/Collider.h"
#include "../spatial/collider/SphereCollider.h"

class Node {
public:
    Mesh *mesh;
    Collider *collider;
    SphereCollider *sphCollider = nullptr;

    Node(Mesh *mesh, Collider *collider);
    Node(Mesh *mesh, SphereCollider *sphCollider);
    Node();

    void setTranslation(sf::Vector3<double> v);
};


#endif //UNTITLED3_NODE_H
