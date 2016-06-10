#pragma once

#include "InterfaceComponent.h"

#include <SDL.h>
class TextInput : public InterfaceComponent
{
public:
	TextInput();
	~TextInput();

	virtual void handleEvent(SDL_Event* );
};

