#include <iostream>
#include "src/Engine.h"
#include "src/Mesh.h"
#include "src/Matrix.h"
#include "src/Triangle.h"
int main() {

    auto *engine = new Engine();
    auto cube = Mesh::getUnitCube();
    Triangle zi ={{3.0,2.0,1.0},{0.0,1.0,1.0},{0.0,0.0,0.0}};
    float theta = 0;

    while (engine->isRunning()) {
//      engine->pushTriangle(std::make_tuple(sf::Vector3(0.0,0.0,0.0),sf::Vector3(0.0,180.0,0.0),sf::Vector3(180.0,0.0,0.0)));
        for(auto tri : cube.getTrianglesProjected(theta)){
            engine->pushTriangle(tri);
        }
        theta += 0.01;
        engine->run();
    }


    return 0;
}
