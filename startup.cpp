#include "startup.h"

Startup::Startup()
{
	SDL();
	SDLImage();
	Window();
	SDLMixer();

	screen;

	SDL_GetWindowSize(window, &vw, &vh);
	screen.w = vw;
	screen.h = vh;
	screen.x = 0;
	screen.y = 0;

	if (SDL_NumJoysticks() != 0)
	{
		SDL_GameController *controller = SDL_GameControllerOpen(0);
		SDL_GameControllerEventState(SDL_ENABLE);
	}
}

int Startup::SDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}
	else
	{
		SDL_Log("SDL initialised OK!\n");
		return 0;
	}
}

int Startup::SDLImage()
{
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
			"SDL_image init error: %s\n", IMG_GetError());
		return 1;
	}
	SDL_Log("SDL_image initialised OK!\n");
	return 0;
}

int Startup::SDLMixer()
{
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
			"SDL_mixer init error: %s\n   PERHAPS NO HEADPHONES/SPEAKERS CONNECTED\n", Mix_GetError());
		return 1;
	}
	SDL_Log("SDL_mixer initialised OK!\n");
}

void Startup::Window()
{
	SDL_GetDesktopDisplayMode(0, &screenDM);

	SDL_CreateWindowAndRenderer(
		(screenDM.w/2),
		(screenDM.h/2),
		SDL_WINDOW_RESIZABLE,
		&window,
		&renderer
	);
	
	SDL_SetWindowTitle(window, "Daniel Downes - Games Programming - 14520077");
	SDL_ShowCursor(false);

	SDL_RenderSetLogicalSize(renderer, screenDM.w/2, screenDM.h/2);
}

void Startup::Render(SDL_Renderer* renderer, std::vector<Sprite*> spriteList, enemyManager em, Player* player)
{	
	SDL_RenderClear(renderer);	
	
	//floor
	SDL_RenderCopy(renderer, spriteList[0]->texture, NULL, NULL);

	//bullets
	for (int i = 0; i < player->bulletList.size(); i++)
	{
		
		SDL_RenderCopyEx(renderer, player->bulletList[i]->texture, &player->bulletList[i]->bulletSource, &player->bulletList[i]->bulletPos, player->bulletList[i]->angle - 90, NULL, SDL_FLIP_VERTICAL);
	}
	
	//enemies
	for (int i = 0; i < em.enemyList.size(); i++)
	{
		SDL_RenderCopyEx(renderer, em.enemyList[i]->texture, &em.enemyList[i]->enemySource, &em.enemyList[i]->enemyPos, em.enemyList[i]->angle - 90, NULL, SDL_FLIP_VERTICAL);
	}	

	//player
	SDL_RenderCopyEx(renderer, player->texture, &player->playerSource, &player->playerPos, player->angle - 90, NULL, SDL_FLIP_VERTICAL);

	//mouse
	SDL_RenderCopy(renderer, spriteList[1]->texture, &spriteList[1]->sourceRect, &spriteList[1]->posRect);

	//health text
	SDL_RenderCopy(renderer, spriteList[4]->texture, NULL, &spriteList[4]->posRect);

	//health bars
	for (int i = 5; i < spriteList.size(); i++)
	{
		SDL_RenderCopy(renderer, spriteList[i]->texture, NULL, &spriteList[i]->posRect);
	}

	SDL_RenderPresent(renderer);
}

void Startup::Splash(std::vector<Sprite*> spriteList, bool* splashB, bool* menu)
{
	SDL_RenderClear(renderer);

	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//registers keyboard events from the user
		case SDL_QUIT:
			SDL_Log("User closed application.");
			*splashB = false;
			*menu = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_F11:
				if (full == false)
				{
					full = true;
					SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					SDL_RenderSetLogicalSize(renderer, screen.w, screen.h);
					SDL_Log("User entered fullscreen . . .");
				}
				else if (full == true)
				{
					full = false;
					SDL_SetWindowFullscreen(window, 0);
					SDL_Log("User exited fullscreen . . .");
					SDL_RenderSetLogicalSize(renderer, screen.w, screen.h);
				}
				break;
			case SDLK_ESCAPE:
				SDL_Log("User closed application . . .");
				*splashB = false;
				*menu = true;
				break;
			case SDLK_RETURN:
			case SDLK_RETURN2:
				*splashB = false;
				break;
			default:
				break;
			}
		}
	}

	
	SDL_RenderCopy(renderer, spriteList[2]->texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void Startup::Dead(std::vector<Sprite*> spriteList, bool* dead)
{
	SDL_RenderClear(renderer);

	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//registers keyboard events from the user
		case SDL_QUIT:
			SDL_Log("User closed application.");
			*dead = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_F11:
				if (full == false)
				{
					full = true;
					SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					SDL_RenderSetLogicalSize(renderer, screen.w, screen.h);
					SDL_Log("User entered fullscreen . . .");
				}
				else if (full == true)
				{
					full = false;
					SDL_SetWindowFullscreen(window, 0);
					SDL_Log("User exited fullscreen . . .");
					SDL_RenderSetLogicalSize(renderer, screen.w, screen.h);
				}
				break;
			case SDLK_ESCAPE:
				SDL_Log("User closed application . . .");
				*dead =false;
				break;
			case SDLK_RETURN:
			case SDLK_RETURN2:
				*dead = false;
				break;
			default:
				break;
			}
		}
	}


	SDL_RenderCopy(renderer, spriteList[3]->texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}
