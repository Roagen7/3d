//
// Created by roagen on 21.08.2021.
//

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


    this->convertTriangles();
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
    for(triangle tri : triangles){
        glBegin(GL_TRIANGLES);
        glColor3f(1, 1, 1);
        glVertex3f(std::get<0>(tri).x, std::get<0>(tri).y, std::get<0>(tri).z);
        glVertex3f(std::get<1>(tri).x, std::get<1>(tri).y, std::get<1>(tri).z);
        glVertex3f(std::get<2>(tri).x, std::get<2>(tri).y, std::get<2>(tri).z);
        glEnd();
    }


}

void Engine::convertTriangles() {
    for(triangle& tri : triangles){
        std::get<0>(tri).x = -1.0 + 2.0 *  std::get<0>(tri).x / windowSize.width;
        std::get<0>(tri).y = 1.0 - 2.0 *  std::get<0>(tri).y / windowSize.width;
        std::get<0>(tri).z = 1.0 - 2.0 *  std::get<0>(tri).z / windowSize.width;
        std::get<1>(tri).x = -1.0 + 2.0 *  std::get<1>(tri).x / windowSize.width;
        std::get<1>(tri).y = 1.0 - 2.0 *  std::get<1>(tri).y / windowSize.width;
        std::get<1>(tri).z = 1.0 - 2.0 *  std::get<1>(tri).z / windowSize.width;
        std::get<2>(tri).x = -1.0 + 2.0 *  std::get<2>(tri).x / windowSize.width;
        std::get<2>(tri).y = 1.0 - 2.0 *  std::get<2>(tri).y / windowSize.width;
        std::get<2>(tri).z = 1.0 - 2.0 *  std::get<2>(tri).z / windowSize.width;
    }
}

void Engine::pushTriangle(triangle tri) {
    this->triangles.push_back(tri);
}

void Engine::pushTriangle(sf::Vector3<double> f, sf::Vector3<double> s, sf::Vector3<double> t) {
    this->triangles.emplace_back(f,s,t);
}

void Engine::emptyTriangles() {
    this->triangles.clear();
}

void Engine::pushTriangle(sf::Vector3<double> vertices[3]) {
    this->triangles.emplace_back(vertices[0], vertices[1], vertices[2]);
}




