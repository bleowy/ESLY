#include "Texture.h"
#include "Game.h"

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <string>

/*
	If you put empty string into path texture won't load.
*/
Texture::Texture(std::string path, int x, int y) : engineRenderer(Game::graphics.getRenderer()){
	if(!path.empty()){
		load(path);
		textureRect.x = x;
		textureRect.y = y;
	}
}

Texture::~Texture()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
}

void Texture::load(std::string path)
{
	SDL_Surface* image = IMG_Load(path.c_str());
	if (image == NULL){
		std::cout << "Unable to load texture with path:" << path << std::endl;
	}
	else{
		texture = SDL_CreateTextureFromSurface(engineRenderer, image);

		if (texture == NULL)
			std::cout << SDL_GetError() << std::endl;
		else{
			SDL_QueryTexture(texture, NULL, NULL, &textureRect.w, &textureRect.h);
		}
		SDL_FreeSurface(image);
	}
}


/*
	Render related
*/

void Texture::render()
{
	SDL_RenderCopy(engineRenderer, texture, NULL, &textureRect);
}


/*
	Getters
*/

int Texture::getWidth()
{
	return textureRect.w;
}

int Texture::getHeight()
{
	return textureRect.h;
}

const SDL_Rect* Texture::getTextureRect()
{
	return &textureRect;
}

SDL_Texture* Texture::getTexture(){
	return texture;
}

/*
	Setters
*/

void Texture::setHeight(int height)
{
	textureRect.h = height;
}

void Texture::setWidth(int width)
{
	textureRect.w = width;
}

void Texture::setX(int x)
{
	textureRect.x = x;
}

void Texture::setY(int y)
{
	textureRect.y = y;
}

