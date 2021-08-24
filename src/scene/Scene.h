//
// Created by roagen on 21.08.2021.
//

#ifndef UNTITLED3_SCENE_H
#define UNTITLED3_SCENE_H


#include "../mesh/Mesh.h"
#include "../transformation/VectorUtils.h"
#include "../spatial/light/Light.h"
#include "../spatial/camera/Camera.h"

class Scene {
private:
    std::vector<Triangle> trisLocallyTransformed;
    std::vector<Triangle> trisGloballyTransformed;
    std::vector<Triangle> trisProjected;
protected:
    //children
    Camera camera;
    std::vector<Mesh> meshes;
    std::vector<Light> lights;
    //materials[0] = default material
    std::vector<Material> materials = {Material::defaultMaterial()}; // all of the materials that are supposed to be used
public:
    void pushMesh(const Mesh& m);


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
