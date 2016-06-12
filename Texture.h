#pragma once

#include <SDL2/SDL.h>

#include <vector>
#include <string>


class Texture
{
protected:
	SDL_Renderer* engineRenderer;
	SDL_Texture* texture;
	SDL_Rect textureRect;
	virtual void load(std::string);
public:
	Texture(std::string path, int, int);
	Texture(int, int);
	virtual ~Texture();
	virtual void render();
	void remove();

	/*
	GETTERS AND SETTERS
	*/
	int getWidth();
	int getHeight();
	const SDL_Rect* getTextureRect();
	SDL_Texture* getTexture();
	void setHeight(int);
	void setWidth(int);
	void setX(int);
	void setY(int);

};
