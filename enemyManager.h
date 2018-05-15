#pragma once
#include "SDL.h"
#include "enemy.h"
#include "player.h"
#include <vector>
#include "SDL_mixer.h"

class enemyManager
{
public:
	enemyManager(SDL_Renderer* renderer, SDL_DisplayMode screenDM);

	std::vector<Enemy*> enemyList;

	int timer = 0;
	int counter = 0;
	int posx, posy;
	SDL_DisplayMode DM;
	int random;

	std::vector<double> tempPos = {0,0};

	void UpdateEnemies(SDL_Renderer* renderer, Player* player, Sprite* bar);
	void CreateEnemy(SDL_Renderer* renderer);
	void SpawnPoint();
	void DetectCollisions(Player* player);
};