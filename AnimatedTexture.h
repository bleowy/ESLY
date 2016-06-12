#pragma once

#include <SDL2/SDL.h>

#include "Texture.h"

class AnimatedTexture : public Texture{
private:
	void load(std::string);
};