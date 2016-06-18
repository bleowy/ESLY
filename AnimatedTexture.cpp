#include "AnimatedTexture.h"

/*
	This class inherits from TiledTexture and uses its createClips method and vector called tiles.
*/
AnimatedTexture::AnimatedTexture(std::string filePath, int width, int height, int number, int speed) : frame(width, height, number, speed)
, TiledTexture(filePath, height, width) {

}

/*
	Control methods.
*/

/*
	Higher value = slower animation.
*/
void AnimatedTexture::setSpeed(int speed){
	frame.speed = speed;
}

/*
	Stops the whole animation.
*/
void AnimatedTexture::stop(){
	frame.currentFrame = 0;
	frame.pause = true;
}
/*
	Pauses the animation.
*/
void AnimatedTexture::pause(){
	frame.pause = true;
}

/*
	Play the animation.
*/
void AnimatedTexture::play(){
	frame.pause = false;
}


/*
	Render and update.
*/
void AnimatedTexture::update(){
	if(!frame.pause){
		++frame.currentFrame;
	 		if( frame.currentFrame / frame.speed >= frame.number ) { frame.currentFrame = 0; }
	}
}

void AnimatedTexture::render(){
	TiledTexture::render(frame.currentFrame / frame.speed);
}


