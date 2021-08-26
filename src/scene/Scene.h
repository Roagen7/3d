//
// Created by roagen on 21.08.2021.
//

#ifndef UNTITLED3_SCENE_H
#define UNTITLED3_SCENE_H


#include "../mesh/Mesh.h"
#include "../transformation/VectorUtils.h"
#include "../spatial/light/Light.h"
#include "../spatial/camera/Camera.h"
#include "../spatial/collider/Collider.h"
#include "../spatial/collider/SphereCollider.h"

class Scene {
private:
    std::vector<Triangle> trisLocallyTransformed;
    std::vector<Triangle> trisGloballyTransformed;
    std::vector<Triangle> trisProjected;
protected:
    //children
    Camera camera;
    std::vector<Mesh> meshes;
    std::vector<SphereCollider> sphereColliders;
    std::vector<Light> lights;

    std::vector<Material> materials = {Material::defaultMaterial()}; // all of the materials that are supposed to be used and default


public:
    sf::Vector2u windowSize;
    Scene();


    void pushMesh(const Mesh& m);
    void pushSphereCollider(const SphereCollider& c);
    void localTransform();
    void globalTransform(Matrix matrix);
    void painterSort();
    void applyLight();
    void project(Matrix matrix);
    void cleanup();

    void buildFrame(Matrix globalTransformMatrix, Matrix projectionMatrix);
    std::vector<Triangle> getBuiltTris();
    //run this every frame to update scene children properties
    virtual void updateProperties(std::vector<sf::Keyboard::Key> keysPressed, sf::Vector2<double> mouseDelta);
};


#endif //UNTITLED3_SCENE_H
