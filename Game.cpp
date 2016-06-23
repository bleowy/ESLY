#include "Game.h"
#include "Texture.h"
#include "TiledTexture.h"
#include "Button.h"
#include "Sound.h"
#include "AnimatedTexture.h"
#include "Rectangle.h"

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
	Button button(200, 150, 400, 200);
	while (!isClosed) {
		listenForEvent();
		activeScreen -> update();
		graphics.startDrawing();
		activeScreen -> render();
		button.render();
		SDL_SetRenderDrawColor(graphics.getRenderer(), 255, 255, 255, 255); // After using shapes we have to set render draw color to default.
		graphics.endDrawing();
	}
}

/*
	Every event will be send throught this method to screen.
*/

void Game::listenForEvent() {
	while (SDL_PollEvent(&graphics.getEvent()))
	{
		if (graphics.getEvent().type == SDL_QUIT)
			closeGame();
		if(graphics.getEvent().type != 1024 && graphics.getEvent().type != 512) // 1024 mouse enters window, 512 leaves.
			std::cout << "Event Occured:" << graphics.getEvent().type << std::endl;
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
