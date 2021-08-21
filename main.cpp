#include <iostream>
#include "src/Engine.h"
#include "src/mesh/Mesh.h"
#include "src/transformation/Matrix.h"
#include "src/mesh/Triangle.h"
int main() {

    auto *engine = new Engine();
    auto cube = Mesh::getUnitCube();

//    float theta = 0;
    Scene scene;
    scene.pushMesh(cube);
//    auto transl = Matrix::getTranslationMarix({0.0,0.0,3.0});
    auto proj = Matrix::getProjectionMatrix();


    float theta = 0;
    while (engine->isRunning()) {
//        for(auto tri : cube.getTrianglesProjected(theta)){
//            engine->pushTriangle(tri);
//
//
//        }
        auto globTransf =  Matrix::getRotationMatrixAxisX(theta) * Matrix::getRotationMatrixAxisZ(theta);
        globTransf = globTransf * Matrix::getTranslationMarix({0.0,0.0,5.0});
//
        theta += 0.01;
//
        engine->drawSceneFrame(scene, globTransf, proj);
        engine->run();
    }


    return 0;
}
