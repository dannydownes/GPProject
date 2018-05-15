#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include "bullet.h"

class Player
{
public:
	SDL_Rect playerPos;
	SDL_Rect playerSource;
	
	double angle;

	SDL_Surface* temp;
	SDL_Texture* texture;
	int health = 100;

	Player();
	Player(SDL_Renderer* renderer);

	std::vector<Bullet*> bulletList;

	void Shoot(SDL_Renderer* renderer);
	void UpdateShots();
};