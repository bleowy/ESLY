#pragma once

#include <SDL2/SDL.h>

class GUI
{
protected:
	SDL_Rect rect = {0,0,0,0};
private:
	static bool click(int, int, SDL_Rect);
public:
	bool onClick();
	virtual void render();
	virtual void update();
};
