#pragma once

#include "Texture.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>

class TextTexture : public Texture
{
private:
	SDL_Color color;
	TTF_Font *font;
	std::string text;
	std::string path = "Assets/Fonts/AppleGaramond.ttf";
	int size;
	virtual void load();
	void create();
public:
	TextTexture(std::string, std::string, int = 12, int = 0, int = 0, int = 255, int = 0, int = 255);
	TextTexture(std::string, int = 12, int = 0, int = 0, int = 255, int = 0, int = 255);
	void setText(std::string);
	void setFont(std::string);
	void setSize(int);
	void setColor(int, int, int);
	void centerText(SDL_Rect);
};

