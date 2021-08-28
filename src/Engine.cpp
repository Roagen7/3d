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
    this->mousePrevPosRelative =sf::Vector2<double>(sf::Mouse::getPosition(*window));
    this->mousePosRelative = sf::Vector2<double>(sf::Mouse::getPosition(*window));
    this->window->setMouseCursorVisible(false);
}

void Engine::mapEvents() {
    sf::Event event{};
    keysPressed.clear();
    while(window->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window->close();
        } else if(event.type == sf::Event::Resized){
            glViewport(0,0,(int) event.size.width, (int) event.size.height);
        } else if(event.type == sf::Event::KeyPressed){
            keysPressed.push_back(event.key.code);
        }
    }
}


void Engine::render() {
    glClearColor(bgColor.r/255.0,bgColor.g/255.0,bgColor.b/255.0,bgColor.a/255.0);
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
    this->updateMousePos();
    this->lockMouse();
    this->mapEvents();
    this->render();

}

void Engine::drawTriangles() {


    for(Triangle tri : triangles){

        glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
        if(this->drawMaterials && tri.material != nullptr){
            glEnable(GL_TEXTURE_2D);
            sf::Texture::bind(&tri.material->texture);

        }

        glBegin(GL_TRIANGLES);
        tri.col += sf::Vector3<double>(this->bgColor.r, this->bgColor.g, this->bgColor.b) * 0.5;

        glColor3f(tri.col.x / 255, tri.col.y/255, tri.col.z/255);

        if(this->drawMaterials && tri.material != nullptr){

            glTexCoord2f(tri.q[0].x/ tri.q[0].z, tri.q[0].y/ tri.q[0].z);
            glVertex3f(tri.v[0].x, tri.v[0].y, tri.v[0].z);
            glTexCoord2f(tri.q[1].x / tri.q[1].z, tri.q[1].y / tri.q[1].z);
            glVertex3f(tri.v[1].x, tri.v[1].y, tri.v[1].z);
            glTexCoord2f(tri.q[2].x / tri.q[2].z, tri.q[2].y / tri.q[2].z);
            glVertex3f(tri.v[2].x, tri.v[2].y, tri.v[2].z);
        } else {
            glVertex3f(tri.v[0].x, tri.v[0].y, tri.v[0].z);
            glVertex3f(tri.v[1].x, tri.v[1].y, tri.v[1].z);
            glVertex3f(tri.v[2].x, tri.v[2].y, tri.v[2].z);
        }
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

void Engine::drawSceneFrame(Scene* scene, Matrix globalTransformMatrix, Matrix projectionMatrix) {
    scene->buildFrame(globalTransformMatrix, projectionMatrix);
    for(auto tri : scene->getBuiltTris()){

        this->pushTriangle(tri);
    }
    scene->cleanup();

}

sf::Vector2u Engine::getWindowSize() {
    return this->window->getSize();
}

sf::Vector2<double> Engine::getMouseDelta() {
    return this->mousePosRelative - this->mousePrevPosRelative;
}

void Engine::updateMousePos() {
    this->mousePrevPosRelative.x = this->getWindowSize().x/2;
    this->mousePrevPosRelative.y = this->getWindowSize().y/2;
    this->mousePosRelative = sf::Vector2<double>(sf::Mouse::getPosition(*this->window));
//    std::cout << this->mousePosRelative.x << " " << this->mousePosRelative.y << std::endl;
}

void Engine::lockMouse() {
    sf::Mouse::setPosition({(int) this->getWindowSize().x / 2, (int) this->getWindowSize().y / 2}, *window);
}








