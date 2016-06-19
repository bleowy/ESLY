#include "InterfaceComponent.h"
#include "TextTexture.h"

#include <SDL2/SDL.h>

class Window : public InterfaceComponent{
private:
	TextTexture windowName;
	void move();
	void close();
public:
	using InterfaceComponent::InterfaceComponent;
	virtual void render();
	virtual void update();
	virtual void handleEvent(SDL_Event*);
};