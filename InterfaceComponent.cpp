#include "InterfaceComponent.h"
#include "Game.h"

/*
	This is a abstract class for GUI components like buttons, textinputs etc.
	TODO list:
	-Animation of components.
*/

/*
	If you don't want to create component with texture, this constructor allows you to create invisible component :D
	TODO: default texture in every component.
*/
InterfaceComponent::InterfaceComponent(std::string name, int x, int y , int width, int height) : texture("", x, y), event(&Game::graphics.getEvent())
{
	
}

/*
	This will create component with texture.Width and Height are the same as texture.
*/
InterfaceComponent::InterfaceComponent(std::string name, std::string texturePath, int x, int y) : texture(texturePath, x, y), event(&Game::graphics.getEvent()) {
	position = {x,y,texture.getWidth(),texture.getHeight()};
}

InterfaceComponent::~InterfaceComponent()
{
}


/*
	Rendering
*/
void InterfaceComponent::render(){
	texture.render();
}

/*
	Updating
*/
void InterfaceComponent::update(){

}

/*
	Handling event
*/
void InterfaceComponent::handleEvent(SDL_Event* event){
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		wasClicked = onClick(x,y);
	}
}

/*
	
*/
bool InterfaceComponent::clicked(){
	if(wasClicked){
		wasClicked = false;
		return true;
	}else{
		return false;
	}
}

/*
	If your compoment was clicked function returns true.
*/
bool InterfaceComponent::onClick(int clickX, int clickY){
	if(clickX >= position.x && clickX < position.x + position.w && clickY >= position.y && clickY < position.y + position.h){
		isActive = true;
		return isActive;
	}else{
		isActive = false;
		return isActive;
	}
}

/*
	Getters and Setters
*/

void InterfaceComponent::setX(int x){
	position.x = x;
}

void InterfaceComponent::setY(int y){
	position.y = y;
}

void InterfaceComponent::setWidth(int width){
	position.w = width;
}

void InterfaceComponent::setHeight(int height){
	position.h = height;
}

int InterfaceComponent::getX(){
	return position.x;
}

int InterfaceComponent::getY() {
	return position.y;
}

int InterfaceComponent::getWidth() {
	return position.w;
}

int InterfaceComponent::getHeight() {
	return position.h;
}