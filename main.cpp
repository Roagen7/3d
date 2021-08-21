#include <iostream>
#include "src/Engine.h"
#include "src/mesh/Mesh.h"
#include "src/transformation/Matrix.h"
#include "src/mesh/Triangle.h"
int main() {

    auto *engine = new Engine();
    auto cube = Mesh::getUnitCube();
//    Triangle zi ={{0.0,0.0,0.0},{180.0,0.0,0.0},{0.0,180.0,0.0}};
    float theta = 0;

    while (engine->isRunning()) {

        for(auto tri : cube.getTrianglesProjected(theta)){
            engine->pushTriangle(tri);
        }

//        engine->pushTriangle(zi);
        theta += 0.01;

        engine->run();
    }


    return 0;
}
