#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <vector>

class Texture;

class Graphics
{
    public:
        Graphics();

        SDL_Renderer* getRenderer();
        SDL_Window* getWindow();
        SDL_Event& getEvent();
		void startDrawing();
		void endDrawing();
        void removeGraphics();
    private:
        bool initializeSDL();

        SDL_Renderer* graphicsRenderer;
        SDL_Window* graphicsWindow;
        SDL_Event graphicsEvent;
};
#endif GRAPHICS_H
