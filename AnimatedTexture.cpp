#include "AnimatedTexture.h"

/*
	This class inherits from TiledTexture and uses its createClips method and vector called tiles.
*/
AnimatedTexture::AnimatedTexture(std::string filePath, int width, int height, int number) : frame(width, height, number)
, TiledTexture(filePath, height, width, width, height) {

}

void AnimatedTexture::update(){
	++frame.currentFrame;
	 if( frame.currentFrame / 5 >= frame.number ) { frame.currentFrame = 0; }
}

void AnimatedTexture::render(){
	TiledTexture::render(frame.currentFrame / 5);
}