#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#include "Texture.h"

class TiledTexture : public Texture
{
private:
	std::vector<SDL_Rect> tiles;

	void createClips(int = 32, int = 32, int = 32, int = 32);
public:
	TiledTexture(std::string);
	TiledTexture(std::string, int, int, int, int);
	~TiledTexture();
	
	void render(int);
	/*
		Getters and Setters.
	*/
	const SDL_Rect* getTile(int id);
};

