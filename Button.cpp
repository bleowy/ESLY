#include "Button.h"
#include "Game.h"


Button::Button(int x, int y, int width, int height) : buttonRect(x,y,width,height,255,120,255,75), buttonText("Click me", 24, x + width / 4 , y + height / 4, 255, 0, 255){
	buttonText.centerText(buttonRect.getRect());
}

void Button::render(){
	buttonRect.render();
	buttonText.render();
}

void Button::update(){

}