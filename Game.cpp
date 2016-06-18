#include "Game.h"
#include "Texture.h"
#include "TiledTexture.h"
#include "Button.h"
#include "Sound.h"
#include "AnimatedTexture.h"

#include <iostream>
#include <string>

#undef main

Graphics Game::graphics = Graphics();
Screen* Game::activeScreen = new Screen();

/*
	TODO setup window settings before game start.
*/

Game::Game(){
}

Game::~Game(){

}

/*
	User don't have access to main loop.
	Only way to access it is changing update and render.
*/

void Game::loop(){
	AnimatedTexture animation("Assets/Animations/campfire.png", 64, 64, 5, 5);
	while (!isClosed) {
		listenForEvent();
		
		activeScreen -> update();
		animation.update();
		graphics.startDrawing();
		animation.render();
		activeScreen -> render();
		graphics.endDrawing();
	}
}

/*
	Every event will be send throught this method to screen.
*/

void Game::listenForEvent() {
	while (SDL_PollEvent(&graphics.getEvent()) != 0)
	{
		if (graphics.getEvent().type == SDL_QUIT)
			closeGame();
		activeScreen -> handleEvent(&graphics.getEvent());
	}
}

/*
	Bunch of control methods.
*/

void Game::startGame() {
	loop();
}

void Game::closeGame() {
	isClosed = true;
}

/*
	Getters and Setters.
*/


/*
	TODO:
	This method also should call cleaning method from Screen.
*/
void Game::setScreen(Screen* screen){
	activeScreen = screen;
	std::cout << "Changed screen to:" << activeScreen->getName() << "(" << screen->getName() << ")" << std::endl;
	screen -> render();
}

/*
	Left here for testing pursposes.
*/

int main() {
	Game game;
	game.setScreen(new Screen());
	game.startGame();
	return 0;
}
