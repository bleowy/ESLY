#pragma once

#include <string>

#include "Texture.h"

class InterfaceComponent
{
protected:
	SDL_Rect position;
	SDL_Event* event;
	Texture texture;
	std::string name;
	bool isActive;
	bool wasClicked;
private:
	bool onClick(int, int);
public:
	InterfaceComponent(std::string, int, int, int, int);
	InterfaceComponent(std::string name, std::string texturePath, int x, int y);
	~InterfaceComponent();
	virtual void render();
	virtual void update(); // im not sure about this but I left it here.
	virtual void handleEvent(SDL_Event*);
	bool clicked();

	/*
		Getters and Setters.
	*/

	inline void setX(int);
	inline void setY(int);
	inline void setWidth(int);
	inline void setHeight(int);
	inline int getX();
	inline int getY();
	inline int getWidth();
	inline int getHeight();
};

