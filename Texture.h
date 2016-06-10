#pragma once

#include <SDL.h>

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
	virtual ~Texture();
	virtual void render();
	
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
