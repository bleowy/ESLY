#include "AnimatedTexture.h"

/*
	This class inherits from TiledTexture and uses its createClips method and vector called tiles.
*/
AnimatedTexture::AnimatedTexture(std::string filePath, int width, int height, int number, int speed) : frame(width, height, number, speed)
, TiledTexture(filePath, height, width, width, height) {

}

/*
	Control methods.
*/

/*
	Higher value = slower animation.
*/
void AnimatedTexture::setSpeed(int speed){

}

/*
	Stops the whole animation.
*/
void AnimatedTexture::stop(){

}
/*
	Pauses the animation.
*/
void AnimatedTexture::pause(){

}

/*
	Resume/play the animation.
*/
void AnimatedTexture::play(){

}

/*
	Render and update.
*/
void AnimatedTexture::update(){
	++frame.currentFrame;
	 if( frame.currentFrame / frame.speed >= frame.number ) { frame.currentFrame = 0; }
}

void AnimatedTexture::render(){
	TiledTexture::render(frame.currentFrame / frame.speed);
}


