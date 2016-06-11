#pragma once

#include "Texture.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

class TextTexture : public Texture
{
private:
	SDL_Color color;
	std::string text;
	std::string path;
	void load(std::string, std::string, int, int);
public:
	TextTexture();
	~TextTexture();
};

