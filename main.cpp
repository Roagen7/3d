#include <iostream>
#include "src/Engine.h"
#include "src/mesh/Mesh.h"
#include "src/transformation/Matrix.h"
#include "src/mesh/Triangle.h"
#include "usage/TestScene.h"
#include "src/mesh/material/Material.h"
#include "usage/GravityScene.h"
#include "usage/CollisionScene.h"
#include "usage/SmallScene.h"
#include <chrono>
int main() {
    //initialization of the engine with some basic settings
    auto *engine = new Engine(Environment::config(
            true,
            sf::Color(0x1e2852),
            1
            ));
    auto scene = SmallScene();
//    engine->drawMaterials = true;
//    engine->bgColor = sf::Color(0x1e2852);
    double delta = 0;

//    engine->bgColor = sf::Color::Green;

    while (engine->isRunning()) {
        auto start = std::chrono::high_resolution_clock::now();
        auto proj = Matrix::getProjectionMatrix(engine->getWindowSize());
        auto globTransf = Matrix::getIdentityMatrix();

        engine->drawSceneFrame(&scene, globTransf, proj);
        scene.updateProperties(delta, engine->keysPressed, engine->getMouseDelta());
        engine->run();
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        delta = elapsed.count();

    }


    return 0;
}
