//
// Created by roagen on 21.08.2021.
//

#include <iostream>
#include "Engine.h"

Engine::Engine() {
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    this->windowSize = sf::VideoMode(800,800);

    this->window = new sf::Window(this->windowSize, "OpenGL", sf::Style::Default, settings);
    window->setVerticalSyncEnabled(true);
    window->setActive(true);


}

void Engine::mapEvents() {
    sf::Event event{};
    while(window->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window->close();
        } else if(event.type == sf::Event::Resized){
            glViewport(0,0,(int) event.size.width, (int) event.size.height);
        }
    }
}


void Engine::render() {
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    this->fixTriangles();

    this->drawTriangles();
    this->emptyTriangles();

    window->display();
}

bool Engine::isRunning() {
    return this->window->isOpen();
}

void Engine::run() {
    this->mapEvents();
    this->render();

}

void Engine::drawTriangles() {
    for(Triangle tri : triangles){
        glBegin(GL_TRIANGLES);
        glColor3f(tri.lum, tri.lum, tri.lum);

        glVertex3f(tri.v[0].x, tri.v[0].y, tri.v[0].z);
        glVertex3f(tri.v[1].x, tri.v[1].y, tri.v[1].z);
        glVertex3f(tri.v[2].x, tri.v[2].y, tri.v[2].z);

        glEnd();
    }


}



void Engine::pushTriangle(Triangle tri) {
    this->triangles.push_back(tri);
}



void Engine::emptyTriangles() {
    this->triangles.clear();
}

void Engine::fixTriangles() {
    for(auto& tri : triangles){
        tri = tri.fixed(this->windowSize);
    }
}

void Engine::drawSceneFrame(Scene scene,Matrix globalTransformMatrix, Matrix projectionMatrix) {
    scene.buildFrame(globalTransformMatrix, projectionMatrix);
    for(auto tri : scene.getBuiltTris()){
        this->pushTriangle(tri);
    }
    scene.cleanup();
}





