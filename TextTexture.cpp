#include "TextTexture.h"
#include "Game.h"

TextTexture::TextTexture(std::string path, std::string text, int size, int x, int y, int colorR, int colorG, int colorB) : Texture(x, y), path(path), text(text), size(size)
{
	color = {colorR, colorG, colorB, 1};
	load();
	create();
}

TextTexture::TextTexture(std::string text, int size, int x, int y, int colorR, int colorG, int colorB) : Texture(x,y), text(text), size(size)
{
	color = {colorR, colorG, colorB, 1};
	load();
	create();
}

void TextTexture::create()
{
	remove();

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (textSurface == NULL)
		printf("An error occured while creating a textSurface\n");
	else
	{
		texture = SDL_CreateTextureFromSurface(engineRenderer, textSurface);
		if (texture == NULL)
			printf("Can't create texture for text.\n");
		else
		{
			textureRect.w = textSurface->w;
			textureRect.h = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
}

void TextTexture::load()
{
	font = TTF_OpenFont(path.c_str(), size);
	if (font == NULL)
	{
		printf("Failed to load font, from directory: %s\n", path.c_str());
	}
}

void TextTexture::setText(std::string text)
{
	this->text = text;
	create();
}

//Here might be a memory leak.
void TextTexture::setFont(std::string path)
{
	this->path = path;
	load();
	create();
}

void TextTexture::setSize(int size)
{
	this->size = size;
	create();
}

void TextTexture::setColor(int colorR, int colorG, int colorB)
{
	color = { colorR, colorG, colorB };
	create();
}

/*
	Center the text relative to "parent" object.	
*/
void TextTexture::centerText(SDL_Rect centerTo){
	std::cout << centerTo.x << centerTo.y << std::endl;
	textureRect.y = centerTo.y + centerTo.h / 2 - textureRect.h / 2;
	textureRect.x = centerTo.x + centerTo.w / 2 - textureRect.w / 2;
}