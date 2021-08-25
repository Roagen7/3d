#include <iostream>
#include "src/Engine.h"
#include "src/mesh/Mesh.h"
#include "src/transformation/Matrix.h"
#include "src/mesh/Triangle.h"
#include "usage/TestScene.h"
#include "src/mesh/material/Material.h"
#include "usage/GravityScene.h"

int main() {
    //initialization of the engine with some basic settings
    auto *engine = new Engine();
    auto scene = GravityScene();
    engine->drawMaterials = true;
    engine->bgColor = sf::Color(0x1e2852);

    while (engine->isRunning()) {

        auto proj = Matrix::getProjectionMatrix(engine->getWindowSize());
        auto globTransf = Matrix::getIdentityMatrix();

        engine->drawSceneFrame(&scene, globTransf, proj);
        scene.updateProperties(engine->keysPressed, engine->getMouseDelta());
        engine->run();
    }


    return 0;
}
