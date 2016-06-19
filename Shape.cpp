#include "Shape.h"

Shape::Shape(int x, int y, int width, int height, int r, int g, int b, int a) : renderer(Game::graphics.getRenderer()){
	rect = {x,y,width,height};
	color = {r,g,b,a};
}

void Shape::render(){
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}
