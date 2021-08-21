//
// Created by roagen on 21.08.2021.
//

#ifndef UNTITLED3_SCENE_H
#define UNTITLED3_SCENE_H


#include "../mesh/Mesh.h"

class Scene {
private:
    std::vector<Mesh> meshes;
    std::vector<Triangle> trisTransformed;
    std::vector<Triangle> trisProjected;

public:
    void pushMesh(Mesh m);
    void transform(Matrix matrix);
    void project(Matrix matrix);
    void cleanup();
    void buildFrame(Matrix globalTransformMatrix, Matrix projectionMatrix);

};


#endif //UNTITLED3_SCENE_H
