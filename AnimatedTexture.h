#pragma once

#include <SDL2/SDL.h>

#include "TiledTexture.h"

class AnimatedTexture : public TiledTexture{
private:
	struct AnimationFrame
	{
		AnimationFrame(int width, int height, int number, int speed) : width(width), height(height), number(number), speed(speed), currentFrame(0){}
		int width, height, number, currentFrame, speed;
		bool pause = false;
		SDL_Rect clips[]; // It storage x and y for every frame.
	};
	AnimationFrame frame;
public:
	AnimatedTexture(std::string, int, int, int, int);
	inline void setSpeed(int);
	inline void stop();
	inline void pause();
	inline void play();
	void update();
	void render();
};