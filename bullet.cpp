#include "bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(SDL_Rect playerPos, double playerAngle, SDL_Renderer* renderer)
{
	this->target = false;

	this->bulletPos.x = playerPos.x + (playerPos.w/2);
	this->bulletPos.y = playerPos.y + (playerPos.h/2);
	this->bulletPos.w = 10;
	this->bulletPos.h = 16;

	this->bulletSource.x = 0;
	this->bulletSource.y = 0;
	this->bulletSource.w = 31;
	this->bulletSource.h = 36;

	angle = playerAngle;

	char* player = "..\\assets\\sprites\\bullet.png";
	temp = IMG_Load(player);
	texture = SDL_CreateTextureFromSurface(renderer, temp);
}

void Bullet::Move()
{
	//remove if and brackets for homing bullets
	if (this->target == false)
	{
		SDL_GetMouseState(&mousex, &mousey);
		dx = (bulletPos.x + (bulletPos.w / 2) - mousex);
		dy = (bulletPos.y + (bulletPos.h / 2) - mousey);

		direction = sqrtf((dx*dx) + (dy*dy));

		dx /= direction;
		dy /= direction;

		this->target = true;
	}
	
	this->bulletPos.x -= dx * speed;
	this->bulletPos.y -= dy * speed;
}