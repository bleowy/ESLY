#pragma once

#include <SDL2/SDL.h>

#include "TiledTexture.h"

class AnimatedTexture : public TiledTexture{
private:
	struct AnimationFrame
	{
		AnimationFrame(int width, int height, int number) : width(width), height(height), number(number), currentFrame(0){}
		int width, height, number, currentFrame;
		SDL_Rect clips[]; // It storage x and y for every frame.
	};
	AnimationFrame frame;
public:
	AnimatedTexture(std::string, int, int, int);
	void update();
	void render();
};