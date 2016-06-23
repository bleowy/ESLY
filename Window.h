#include "GUI.h"
#include "TextTexture.h"
#include "Rectangle.h"

#include <SDL2/SDL.h>

class Window{
private:
	/*
	TextTexture windowName;
	Rectangle bar;
	*/
	void move();
	void close();
public:
	Window(SDL_Rect, SDL_Color, std::string = "");
	virtual void render();
	virtual void update();
	virtual void handleEvent(SDL_Event*);
};
