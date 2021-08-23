#include <iostream>
#include "src/Engine.h"
#include "src/mesh/Mesh.h"
#include "src/transformation/Matrix.h"
#include "src/mesh/Triangle.h"
#include "usage/TestScene.h"
#include "src/mesh/material/Material.h"

int main() {
    //initialization of the engine with some basic settings
    auto *engine = new Engine();
    auto scene = TestScene();
    auto mat = Material();
    mat.getTextureFromFile("../assets/texture/box.jpg"); // to change - material should be a part of a mesh
    engine->material = mat;
    engine->drawMaterials = true;

    float theta = 0;
    while (engine->isRunning()) {

        auto proj = Matrix::getProjectionMatrix(engine->getWindowSize());
        auto globTransf =   Matrix::getRotationMatrixAxisX(theta) * Matrix::getRotationMatrixAxisZ(theta) * Matrix::getTranslationMarix({0.0,0.0,15.0});
        globTransf = Matrix::getIdentityMatrix();
        theta += 0.01;
        engine->drawSceneFrame(scene, globTransf, proj);
        scene.updateProperties(engine->keysPressed, engine->getMouseDelta());
        engine->run();
    }


    return 0;
}
