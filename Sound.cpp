#include "Sound.h"

Sound::Sound(std::string soundPath){
	load(soundPath);
}

/*
	This method accepts path to file as string.
	TODO:
	Loading through package manager. 	
*/
void Sound::load(std::string soundPath){
	sound = Mix_LoadMUS(soundPath.c_str());
	if(sound == NULL){
		std::cout << "Failed to load" << soundPath << std::endl;
		loaded = false;
	}else{
		loaded = true;
	}	
}

/*
	After loading sound you have to call this method to "hear something".
*/
void Sound::play(){
	if(loaded && Mix_PlayingMusic() == 0){
		Mix_PlayMusic(sound, -1);
	}
}
/*
	Resume current track.
*/
void Sound::resume(){
	if(loaded && Mix_PausedMusic() == 1){
		Mix_ResumeMusic();
	}
}

/*
	Stop the whole track.
*/
void Sound::stop(){
	if(loaded){
		Mix_HaltMusic();
	}
}

/*
	Pause track.
*/
void Sound::pause(){
	if(loaded){
		Mix_PausedMusic();
	}
}