#include "GUI.h"
#include "Game.h"

bool GUI::click(int clickX, int clickY, SDL_Rect rect){
	if(clickX >= rect.x && clickX < rect.x + rect.w && clickY >= rect.y && clickY < rect.y + rect.h)
		return true;
	else
		return false;
}

bool GUI::onClick(){
	if(Game::graphics.getEvent().type != 512 && Game::graphics.getEvent().type != 1024 
		&& Game::graphics.getEvent().type == SDL_MOUSEBUTTONDOWN){
		int x,y;
		SDL_GetMouseState(&x, &y);
		return click(x, y, rect);
	}
}

void GUI::render(){

}

void GUI::update(){

}
