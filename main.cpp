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
        auto globTransf = Matrix::getTranslationMarix({0.0,0.0,15.0});
        theta += 0.01;
        engine->drawSceneFrame(scene, globTransf, proj);
        scene.updateProperties();
        engine->run();
    }


    return 0;
}
