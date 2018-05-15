#include <stdio.h>
#include <iostream>
#include <atltime.h>
#include <vector>
#include "startup.h"
#include "input.h"
#include "sprite.h"
#include "update.h"
#include "enemy.h"
#include "enemyManager.h"
#include "player.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));
	std::vector<Sprite*> spriteList;
	Startup start;
	Input in;
	Update update;

	
	Mix_Music *music = Mix_LoadMUS("..\\assets\\sounds\\music.wav");

	Mix_AllocateChannels(10);
	Mix_PlayMusic(music, 0);

	//type
	// 0 = player sprite
	// 1 = enemy sprite
	// 2 = cursor

	Sprite *splash = new Sprite("Splash", { 1920, 1047 }, {0,0}, 0, start.renderer);
	Sprite *fl00r = new Sprite("Floor", { 500,500 }, { 500, 500 }, 2, start.renderer );
	Sprite *mouse = new Sprite("Cursor", { 30,30 }, { 10 , 10 }, 1, start.renderer);
	Sprite *death = new Sprite("Death Screen", { 1920, 1047 }, { 0,0 }, 3, start.renderer);
	Sprite *health = new Sprite("Health Text", { 150, 30 }, { 25, 10 }, 4, start.renderer);
	Sprite *bar = new Sprite("Health Bar", { 30, 30 }, { 10, 60 }, 5, start.renderer);
	Sprite *bar1 = new Sprite("Health Bar", { 30, 30 }, { 50, 60 }, 5, start.renderer);
	Sprite *bar2 = new Sprite("Health Bar", { 30, 30 }, { 90, 60 }, 5, start.renderer);
	Sprite *bar3 = new Sprite("Health Bar", { 30, 30 }, { 130, 60 }, 5, start.renderer);
	Sprite *bar4 = new Sprite("Health Bar", { 30, 30 }, { 170, 60 }, 5, start.renderer);
	spriteList.push_back(fl00r);
	spriteList.push_back(mouse);
	spriteList.push_back(splash);
	spriteList.push_back(death);
	spriteList.push_back(health);
	spriteList.push_back(bar);
	spriteList.push_back(bar1);
	spriteList.push_back(bar2);
	spriteList.push_back(bar3);
	spriteList.push_back(bar4);

	bool splashB = true;
	bool menu = false;
	bool dead = true;

	while (splashB == true)
	{
		start.Splash(spriteList, &splashB, &menu);
	}
	
	const double MSPU = 1000 / 60;

	Player player(start.renderer);
	enemyManager em(start.renderer, start.screenDM);

	double prev = GetCurrentTime();
	double lag = 0.0;
	while (menu == false)
	{
		double current = GetCurrentTime();
		double elapsed = current - prev;
		prev = current;
		lag += elapsed;

		//input
		in.Player1(start, &menu);

		//update
		while (lag >= MSPU)
		{
			in.UpdateGame(&player, start, spriteList);
			player.UpdateShots();
			update.UpdateGame(&menu, &player);
			em.UpdateEnemies(start.renderer, &player, bar);
			lag -= MSPU;
		}
		//render 
		start.Render(start.renderer, spriteList, em, &player);
	}

	while (dead == true)
	{
		start.Dead(spriteList, &dead);
	}
	return 0;
}