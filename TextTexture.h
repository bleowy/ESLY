#pragma once

#include "Texture.h"

#include <iostream>
#include <SDL.h>
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

