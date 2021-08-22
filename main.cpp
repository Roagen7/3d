#include <iostream>
#include "src/Engine.h"
#include "src/mesh/Mesh.h"
#include "src/transformation/Matrix.h"
#include "src/mesh/Triangle.h"
int main() {

    auto *engine = new Engine();
    auto cube = Mesh::getUnitCube();

    auto ob = Mesh::loadFromObj("../assets/mesh/WC.obj");

    Scene scene;
    scene.pushMesh(ob);




    float theta = 0;
    while (engine->isRunning()) {

        auto proj = Matrix::getProjectionMatrix(engine->getWindowSize());
        auto globTransf =  Matrix::getRotationMatrixAxisX(theta) * Matrix::getRotationMatrixAxisZ(theta);

        globTransf = globTransf * Matrix::getTranslationMarix({0.0,0.0,20.0});

        theta += 0.01;
        engine->drawSceneFrame(scene, globTransf, proj);
        engine->run();
    }


    return 0;
}
