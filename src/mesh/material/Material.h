//
// Created by roagen on 23.08.2021.
//

#ifndef UNTITLED3_MATERIAL_H
#define UNTITLED3_MATERIAL_H


#include <SFML/Graphics/Texture.hpp>

class Material {
public:
    sf::Texture texture;
    void getTextureFromFile(std::string filename);


};


#endif //UNTITLED3_MATERIAL_H
