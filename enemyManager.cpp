#include "enemyManager.h"

enemyManager::enemyManager(SDL_Renderer* renderer, SDL_DisplayMode screenDM)
{
	DM = screenDM;
}

void enemyManager::UpdateEnemies(SDL_Renderer* renderer, Player* player, Sprite* bar)
{
	timer++;

	for (int i = 0; i < enemyList.size(); i++)
	{
		enemyList[i]->EnemyMove(player->playerPos);
		DetectCollisions(player);
	}

	if (enemyList.size() > 30)
	{

	}
	else if (timer % 30 == 0)
	{
		CreateEnemy(renderer);
	}
}

void enemyManager::CreateEnemy(SDL_Renderer* renderer)
{
	SpawnPoint();

	Enemy* temp = new Enemy(renderer, tempPos);

	enemyList.push_back(temp);
}

void enemyManager::SpawnPoint()
{
	double angle = rand() % 360 + 1;
	tempPos[0] = ((DM.w / 4) + 800) * sin(angle);
	tempPos[1] = ((DM.h / 4) + 600) * cos(angle);
	std::cout <<"Enemy spawned at: " << tempPos[0] << "\t" << tempPos[1] << std::endl;
}
void enemyManager::DetectCollisions(Player* player)
{
	for (int i = 0; i < enemyList.size(); i++)
	{
		for (int j = 0; j < enemyList.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			else while (SDL_HasIntersection(&enemyList[i]->enemyPos, &enemyList[j]->enemyPos) == SDL_TRUE)
			{
				enemyList[i]->enemyPos.x += (rand() % ((1) - (-1) + (1)) + (-1));
				enemyList[i]->enemyPos.y += (rand() % ((1) - (-1) + (1)) + (-1));
				enemyList[j]->enemyPos.y -= (rand() % ((1) - (-1) + (1)) + (-1));
				enemyList[j]->enemyPos.x -= (rand() % ((1) - (-1) + (1)) + (-1));
			}
		}
	}

	for (size_t i = 0; i < enemyList.size(); i++)
	{
		for (size_t j = 0; j < player->bulletList.size(); j++)
		{
			if (SDL_HasIntersection(&enemyList[i]->enemyPos, &player->bulletList[j]->bulletPos) == SDL_TRUE)
			{
				player->bulletList.erase(player->bulletList.begin()+j);
				enemyList.erase(enemyList.begin() + i);
			}
		}
	}

	for (int i = 0; i < enemyList.size(); i++)
	{
		if (SDL_HasIntersection(&enemyList[i]->enemyPos, &player->playerPos) == SDL_TRUE)
		{
			if (timer % 200 == 0)
			{
				player->health -= 1;	
			}		
		}
	}
}