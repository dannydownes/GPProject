#include "player.h"

Player::Player()
{

}

Player::Player(SDL_Renderer* renderer)
{
	this->playerPos.x = 250;
	this->playerPos.y = 250;
	this->playerPos.w = 31;
	this->playerPos.h = 37;

	this->playerSource.x = 0;
	this->playerSource.y = 0;
	this->playerSource.w = 31;
	this->playerSource.h = 36;

	angle = 0;
	

	char* player = "..\\assets\\sprites\\player.png";
	temp = IMG_Load(player);
	texture = SDL_CreateTextureFromSurface(renderer, temp);
}

void Player::Shoot(SDL_Renderer* renderer)
{
	Bullet* bullet = new Bullet(playerPos, angle, renderer);

	bulletList.push_back(bullet);
}

void Player::UpdateShots()
{
	for (int i = 0; i < bulletList.size(); i++)
	{
		if (bulletList[i]->bulletPos.x < 0 || bulletList[i]->bulletPos.x > 2000 || bulletList[i]->bulletPos.y < 0 || bulletList[i]->bulletPos.y > 2000)
		{
			bulletList.erase(bulletList.begin() + i);
			printf("bullet deleted");
		}
		else
		{
			bulletList[i]->Move();	
		}
	}
}