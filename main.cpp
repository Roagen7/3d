#include <iostream>
#include "src/Engine.h"
#include "src/mesh/Mesh.h"
#include "src/transformation/Matrix.h"
#include "src/mesh/Triangle.h"
#include "usage/TestScene.h"

int main() {

    auto *engine = new Engine();
    auto scene = TestScene();

    float theta = 0;
    while (engine->isRunning()) {

        auto proj = Matrix::getProjectionMatrix(engine->getWindowSize());
        auto globTransf =   Matrix::getRotationMatrixAxisX(theta) * Matrix::getRotationMatrixAxisZ(theta) * Matrix::getTranslationMarix({0.0,0.0,15.0});
        globTransf = Matrix::getIdentityMatrix();
        theta += 0.01;
        engine->drawSceneFrame(scene, globTransf, proj);
        scene.updateProperties(engine->keysPressed);
        engine->run();
    }


    return 0;
}
