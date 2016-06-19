#include "Rectangle.h"

void Rectangle::render(){
	Shape::render();
	SDL_RenderFillRect(renderer, &rect);
}