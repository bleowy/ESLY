#include "Graphics.h"

#include <iostream>
#include <string>
/*
                Graphics
*/

Graphics::Graphics()
{
    if(initializeSDL())
        std::cout << "Error in loading of graphics module." << std::endl;
}

bool Graphics::initializeSDL()
{
    bool somethingFailed = false;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
         std::cout << "Can't initialize SDL" << std::endl;
         somethingFailed = true;
    }
    else
        graphicsWindow = SDL_CreateWindow("Tales of Maciuszek", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);
        if(graphicsWindow == NULL)
        {
            std::cout << "Can't create window" << std::endl;
            somethingFailed = true;
        }
        else
            graphicsRenderer = SDL_CreateRenderer(graphicsWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(graphicsRenderer == NULL)
            {
                std::cout << "Can't create renderer" << std::endl;
                somethingFailed = true;
            }
            else
            {
                SDL_SetRenderDrawColor(graphicsRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags)) & imgFlags)
                {
                    std::cout << "Can't initialize IMG" << std::endl;
                    somethingFailed = true;
                }
                else if(TTF_Init() == -1)
                {
                    std::cout << "Can't initialize TTF" << std::endl;
                    somethingFailed = true;
                }else if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
                    std::cout << "Can't initialize Mixer" << std::endl;
                    somethingFailed = true;
                }
            }

    return somethingFailed;
}

void Graphics::removeGraphics()
{
    SDL_DestroyRenderer(graphicsRenderer);
    SDL_DestroyWindow(graphicsWindow);
    graphicsRenderer = NULL;
    graphicsWindow = NULL;

    IMG_Quit();
    SDL_Quit();
}

/*
	Methods responsible for drawing
*/

void Graphics::startDrawing() {
	SDL_RenderClear(graphicsRenderer);
}

void Graphics::endDrawing() {
	SDL_RenderPresent(graphicsRenderer);
}

/*
    Getters
*/

SDL_Renderer* Graphics::getRenderer()
{
    return graphicsRenderer;
}

SDL_Event& Graphics::getEvent()
{
    return graphicsEvent;
}

