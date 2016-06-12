#include "TiledTexture.h"
#include "Texture.h"
#include "Game.h"

/*
	This constructor creates default Tiles (32x32).
	Remember to use overrided Render method in this class If you won't do that you will get whole texture on screen.
*/
TiledTexture::TiledTexture(std::string path) : Texture(path, 0, 0){
	createClips();
	//Default tiles setup.
	textureRect.w = 32;
	textureRect.h = 32;
}

/*
	This constructor allows you to create custom clips.
	Remember that width, height should be the same as rowSize and columnSize.
	Remember to use overrided Render method in this class If you won't do that you will get whole texture on screen.
*/
TiledTexture::TiledTexture(std::string path, int rowSize, int columnSize, int width, int height) : Texture(path, 0, 0){
	createClips(rowSize, columnSize, width, height);
	textureRect.w = width;
	textureRect.h = height;
}

TiledTexture::~TiledTexture()
{
}


/*
	This method creates clip for every tile.
	int rowSize, int columnSize, int width, int height
*/
void TiledTexture::createClips(int rowSize, int columnSize, int width, int height){
	for (int row = 0; row < (textureRect.h / rowSize); row++)
	{
		for (int column = 0; column < (textureRect.w / columnSize); column++)
		{
			SDL_Rect clip{column * columnSize, row * rowSize, width, height};
			tiles.push_back(clip);
		}
	}
	//std::cout << "Prepared:" << tile.size() <<"(" << tile.size() - 1 << ")" << "clips." << std::endl;
}

/*
	If you want to render something from TiledTexture you have to know Id of a tile.
	Check createClips() to see how they are indexed or use MapEditor.
*/
void TiledTexture::render(int id){
	SDL_RenderCopy(engineRenderer, texture, getTile(id), &textureRect);
}

/*
	Getters and Setters
*/

/*
	If tile doesn't exist It returns tile with id 0 and prints error to console.
*/
const SDL_Rect* TiledTexture::getTile(int id){
	if (id < tiles.size())
		return &tiles[id];
	else{
		std::cout << "Texture with id " << id << "don't exist" << std::endl;
		return &tiles[0];
	}
}
