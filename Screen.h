#pragma once

#include <SDL2/SDL.h>
#include <iostream>
/*
	This class is a abstract class, framework uses "Screen/State" system.
	Everytime when you need to add new Screen/State in your game, you have to create a class
	that inherits this one.
	Remember to clean up after changing a Screen/State
*/

class Screen
{
protected:
	std::string name = "Junk";
public:
	Screen();
	virtual ~Screen();
	//I don't think I have to explain those two.
	virtual void update();
	virtual void render();
	virtual void handleEvent(SDL_Event*);
	//Those two aren't implemented yet, overriding them is senseless now.
	virtual void pause();
	virtual void resume();
	
	/*
		Getters and Setters
	*/
	std::string getName();
};

