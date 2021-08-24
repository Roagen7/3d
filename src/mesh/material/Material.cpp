//
// Created by roagen on 23.08.2021.
//

#include <iostream>
#include "Material.h"

void Material::getTextureFromFile(std::string filename) {
    sf::Texture tex;
    if(!tex.loadFromFile(filename)){
        std::cout << "duupa" << std::endl;
    } else {
        this->texture = tex;
    }
}

Material Material::defaultMaterial() {
    auto mat = Material();
    mat.texture = sf::Texture();
    return mat;
}
