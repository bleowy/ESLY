#include "TextTexture.h"

#include <iostream>

TextTexture::TextTexture()
{
}


TextTexture::~TextTexture()
{
}

void TextTexture::fontCreate()
{
	textureRemove();

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, fontText.c_str(), fontColor);
	if (textSurface == NULL)
		printf("An error occured while creating a textSurface\n");
	else
	{
		textureContainer = SDL_CreateTextureFromSurface(textureRenderer, textSurface);
		if (textureContainer == NULL)
			printf("Can't create texture for text.\n");
		else
		{
			textureRect.w = textSurface->w;
			textureRect.h = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
}

void TextTexture::fontLoad()
{
	font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (font == NULL)
	{
		printf("Failed to load font, from directory: %s\n", fontPath.c_str());
	}
}

void TextTexture::fontChangeText(std::string fontText)
{
	this->fontText = fontText;
	fontCreate();
}

//Here might be a memory leak.
void TextTexture::fontChange(std::string fontPath)
{
	this->fontPath = fontPath;
	fontLoad();
	fontCreate();
}

void TextTexture::fontChangeSize(int)
{
	this->fontSize = fontSize;
	fontCreate();
}

void TextTexture::fontChangeColor(int colorR, int colorG, int colorB)
{
	fontColor = { colorR, colorG, colorB };
	fontCreate();
}