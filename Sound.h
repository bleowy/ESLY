#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <iostream>

class Sound{
private:
	Mix_Music *sound = NULL;
	bool loaded;
	void load(std::string);
public:
	Sound(std::string);
	void pause();
	void play();
	void stop();
	void resume();
};