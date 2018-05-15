#include "enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(SDL_Renderer* renderer, std::vector<double> position)
{
	SDL_Surface *temp;
	char* enemy = "..\\assets\\sprites\\enemy.png";

	temp = IMG_Load(enemy);
	this->texture = SDL_CreateTextureFromSurface(renderer, temp);

	this->angle = 0;

	this->enemyPos.w = 43;
	this->enemyPos.h = 42;
	this->enemyPos.x = position[0];
	this->enemyPos.y = position[1];
}

void Enemy::EnemyMove(SDL_Rect posRect)
{
	float dx, dy, direction;

	dx = (enemyPos.x + (enemyPos.w / 2)) - (posRect.x + ( posRect.w / 2 ) );
	dy = (enemyPos.y + (enemyPos.h / 2)) - (posRect.y + ( posRect.h / 2 ) );

	angle = ((atan2(dy, dx) * 180.0000) / 3.1416);


	direction = sqrtf((dx*dx) + (dy*dy));

	dx /= direction;
	dy /= direction;

	counter++;

	if (direction <= 10)
	{
		this->enemyPos.x += 0;
		this->enemyPos.y += 0;

		switch (counter)
		{
		case 0:
			this->enemySource = { 0, 149, 43, 29 };
			break;
		case 2:
			this->enemySource = { 50, 149, 43, 26 };
			break;
		case 4:
			this->enemySource = { 101, 148, 42, 40 };
			break;
		case 6:
			this->enemySource = { 151, 149, 40, 36 };
			break;
		case 8:
			this->enemySource = { 195, 148, 43, 36 };
			break;
		case 10:
			counter = 0;
			break;
		default:
			break;
		}
	}
	else
	{
		this->enemyPos.x -= dx * speed;
		this->enemyPos.y -= dy * speed;
	}

	if ( dx*speed == 0 && dy * speed == 0 )
	{
		this->enemySource = { 0, 6, 42, 30 };
	}

	if (dx*speed != 0 || dy * speed != 0)
	{
		switch (counter)
		{
		case 0:
			this->enemySource = { 0, 6, 42, 30 };
			break;
		case 6:
			this->enemySource = { 47, 4, 42, 38 };
			break;
		case 12:
			this->enemySource = { 94, 1, 43, 43 };
			break;
		case 18:
			this->enemySource = { 143, 4, 42, 38 };
			break;
		case 24:
			this->enemySource = { 0, 55, 42, 29 };
			break;
		case 30:
			this->enemySource = { 49, 52, 42, 38 };
			break;
		case 36:
			this->enemySource = { 97, 49, 43, 42 };
			break;
		case 42:
			this->enemySource = { 145, 52, 42, 38 };
			break;
		case 48:
			counter = 0;
			break;
		default:
			break;
		}
	}
}