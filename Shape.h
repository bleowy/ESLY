#include <SDL2/SDL.h>
#include "Game.h"

class Shape{
protected:
	SDL_Color color;
	SDL_Rect rect;
	SDL_Renderer* renderer;
public:
	Shape(int, int, int, int, int, int, int, int);
	virtual void render();
};