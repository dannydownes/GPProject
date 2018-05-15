#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "sprite.h"
#include <vector>
#include "enemyManager.h"
#include "SDL_mixer.h"

class Startup
{
public:
	//constructor
	Startup();
	//declarations
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_DisplayMode screenDM;
	SDL_Rect screen;
	SDL_Texture* mouse;
	SDL_Rect mouseRect;
	int vw, vh;

	//functions
	void Render(SDL_Renderer* renderer, std::vector<Sprite*> spriteList, enemyManager em, Player* player);
	void Splash(std::vector<Sprite*> spriteList, bool* splashB, bool* menu);
	void Dead(std::vector<Sprite*> spriteList, bool* dead);
	bool full = false;
private:	
	//private functions	
	void Window();
	int SDL();
	int SDLImage();
	int SDLMixer();
};