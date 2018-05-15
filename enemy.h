#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "sprite.h"
#include <vector>

class Enemy
{
public:
	Enemy();
	Enemy(SDL_Renderer* renderer, std::vector<double> position);

	int size = 50;
	int angle = 0;
	float speed = 2;
	int counter = 1;

	//passed to renderer
	SDL_Texture *texture;
	//std::vector<int> position;
	SDL_Rect enemyPos;
	SDL_Rect enemySource;

	void EnemyMove(SDL_Rect posRect);
};