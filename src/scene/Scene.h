//
// Created by roagen on 21.08.2021.
//

#ifndef UNTITLED3_SCENE_H
#define UNTITLED3_SCENE_H


#include "../mesh/Mesh.h"
#include "../transformation/VectorUtils.h"
#include "../spatial/light/Light.h"

class Scene {
private:

    std::vector<Triangle> trisLocallyTransformed;
    std::vector<Triangle> trisGloballyTransformed;
    std::vector<Triangle> trisProjected;
protected:
    //children
    std::vector<Mesh> meshes;
    std::vector<Light> lights;
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
    virtual void updateProperties(std::vector<sf::Keyboard::Key> keysPressed);
};


#endif //UNTITLED3_SCENE_H
