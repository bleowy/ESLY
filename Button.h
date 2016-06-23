#pragma once

#include "GUI.h"
#include "Rectangle.h"
#include "TextTexture.h"

class Button : public GUI{
private:
	Rectangle buttonRect;
	TextTexture buttonText;
public:
	Button(int x, int y, int width, int height);
	virtual void render();
	virtual void update();
};