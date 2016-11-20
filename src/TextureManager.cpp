//
//  TextureManager.cpp
//  Pinball
//
//  Created by Dinis Marques Firmino on 02/03/2015.
//  Copyright (c) 2015 DYN. All rights reserved.
//

#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

TextureManager::TextureManager()
{
    
}

void TextureManager::loadTexture(const std::string& ksName /*!< Name of texture to load*/, const std::string& ksFilename/*!< Texture location*/) //!< Load a texture from a file)
{
    /*!< Loading textures from file*/
    sf::Texture texture;

		texture.loadFromFile(ksFilename);
    
    this->textures[ksName] = texture; /*!< Add the texture to the array */
    
    return;
}

sf::Texture& TextureManager::getTexture(const std::string& ksTexture) //!< Returns a texture
{
    return this->textures.at(ksTexture);  /*!< Return the matching texture from the array*/
}