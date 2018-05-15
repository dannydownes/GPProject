#pragma once
#include "SDL.h"
#include "update.h"
#include "startup.h"
#include <iostream>
#include "SDL_mixer.h"

class Input : public Update, public Sprite
{
public:
	//constructor
	Input();

	//public functions
	void Player1(Startup start, bool *dead);
	void UpdateGame(Player* player, Startup start, std::vector<Sprite*> spriteList);
	void AngleSprite(Player* player);
	Mix_Chunk *shot = Mix_LoadWAV("..\\assets\\sounds\\shot.wav");

	int counter = 1;
	int speed = 2;

private:
	bool fullscreen = false;
	int windowHeight;
	int windowWidth;
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;	
	int mousex, mousey;
	bool shooting;

};
