#pragma once
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <iostream>

class Sprite
{
public:	
	//(de)constructors
	Sprite();
	Sprite(std::string tName, std::vector<float> tSize, std::vector<float>tPosition, int tType, SDL_Renderer *renderer);
	~Sprite();

	//variables
	std::string name;
	std::vector<float>position{ 10,10 };
	std::vector<float>size{ 31,36 };
	std::string type;
	SDL_Texture* texture;
	SDL_Rect posRect;
	SDL_Rect sourceRect;
	double angle;

	//functions
	SDL_Texture* loadTexture(int type, SDL_Renderer *renderer);
};
