//
// Created by roagen on 21.08.2021.
//
#ifndef UNTITLED3_ENGINE_H
#define UNTITLED3_ENGINE_H
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <tuple>
#include "mesh/Triangle.h"



class Engine {

private:
    sf::Window* window;
    std::vector<Triangle> triangles;
    sf::VideoMode windowSize;

public:
    Engine();
    void mapEvents();
    bool isRunning();
    void render();
    void pushTriangle(Triangle tri);

    void fixTriangles();
    void drawTriangles();
    void emptyTriangles();
    void run();

};


#endif //UNTITLED3_ENGINE_H