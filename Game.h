#pragma once

#include "Graphics.h"
#include "Screen.h"

#undef main

class Game{
private:
	static Screen* activeScreen;
	bool isClosed = false;
	void loop();
	void listenForEvent();
public:
	static Graphics graphics;
	
	Game();
	~Game();
	void startGame();
	void closeGame();
	void setScreen(Screen*);
};

