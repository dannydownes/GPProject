#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Bullet
{
public:
	Bullet();
	Bullet(SDL_Rect playerPos, double playerAngle, SDL_Renderer* renderer);
	void Move();

	SDL_Rect bulletSource;
	SDL_Rect bulletPos;

	SDL_Texture* texture;
	SDL_Surface* temp;

	double angle;
	double speed = 20;
	bool target;
	float dx, dy, direction;
	int mousex, mousey;
};