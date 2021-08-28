//
// Created by roagen on 21.08.2021.
//
#ifndef UNTITLED3_ENGINE_H
#define UNTITLED3_ENGINE_H
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>
#include "mesh/Triangle.h"
#include "scene/Scene.h"
#include "mesh/material/Material.h"
#include "config/Environment.h"


class Engine {

private:
    sf::Window* window;
    std::vector<Triangle> triangles;
    sf::VideoMode windowSize;
    sf::Vector2<double> mousePrevPosRelative;


public:
    Material material;
    sf::Color bgColor = sf::Color::Black;
    bool drawMaterials = false;
    sf::Vector2<double> mousePosRelative;
    std::vector<sf::Keyboard::Key> keysPressed;

    explicit Engine(Environment env = Environment::config());
    void mapEvents();
    void updateMousePos();
    bool isRunning();
    sf::Vector2u getWindowSize();
    sf::Vector2<double> getMouseDelta();

    void render();
    void pushTriangle(Triangle tri);
    void lockMouse();

    void fixTriangles();
    void drawTriangles();
    void emptyTriangles();
    void drawSceneFrame(Scene* scene, Matrix transformMatrix, Matrix projectionMatrix);

    void run();

};


#endif //UNTITLED3_ENGINE_H
