//
// Created by roagen on 21.08.2021.
//
#ifndef UNTITLED3_ENGINE_H
#define UNTITLED3_ENGINE_H
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <tuple>

typedef std::tuple<sf::Vector3<double>,sf::Vector3<double>, sf::Vector3<double>> triangle;

class Engine {

private:
    sf::Window* window;
    std::vector<triangle> triangles;
    sf::VideoMode windowSize;

public:
    Engine();
    void mapEvents();
    bool isRunning();
    void render();
    void pushTriangle(triangle tri);
    void pushTriangle(sf::Vector3<double> f, sf::Vector3<double> s, sf::Vector3<double> t);
    void pushTriangle(sf::Vector3<double> vertices[3]);
    void convertTriangles();
    void drawTriangles();
    void emptyTriangles();
    void run();

};


#endif //UNTITLED3_ENGINE_H
