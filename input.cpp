#include "input.h"

Input::Input()
{
	fullscreen = false;
}

void Input::Player1(Startup start, bool *dead)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		//registers keyboard events from the user
		case SDL_QUIT:
			SDL_Log("User closed application.");
			*dead = true;
			break;
		case SDL_MOUSEMOTION:
			mousex, mousey;
			SDL_GetMouseState(&mousex, &mousey);
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				shooting = true;
				std::cout << shooting << std::endl;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_F11:
				if (fullscreen == false)
				{
					fullscreen = true;		
					SDL_SetWindowFullscreen(start.window, SDL_WINDOW_FULLSCREEN_DESKTOP);	
					SDL_RenderSetLogicalSize(start.renderer, start.screen.w, start.screen.h);
					SDL_Log("User entered fullscreen . . .");
				}
				else if (fullscreen == true)
				{
					fullscreen = false;						
					SDL_SetWindowFullscreen(start.window, 0);				
					SDL_Log("User exited fullscreen . . .");
					SDL_RenderSetLogicalSize(start.renderer, start.screen.w, start.screen.h);
				}
				break;
			case SDLK_ESCAPE:
				SDL_Log("User closed application . . .");
				*dead = true;
				break;
			case SDLK_w:
			case SDLK_UP:
				up = true;
				break;
			case SDLK_a:
			case SDLK_LEFT:
				left = true;
				break;
			case SDLK_s:
			case SDLK_DOWN:
				down = true;
				break;
			case SDLK_d:
			case SDLK_RIGHT:
				right = true;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
			case SDLK_UP:
				up = false;
				break;
			case SDLK_a:
			case SDLK_LEFT:
				left = false;
				break;
			case SDLK_s:
			case SDLK_DOWN:
				down = false;
				break;
			case SDLK_d:
			case SDLK_RIGHT:
				right = false;
				break;
			}
			break;
			//ADD FOR LOOP FOR CONTROLLER
			//controller input
		case SDL_CONTROLLERBUTTONDOWN:
			switch (event.cbutton.button)
			{
			case SDL_CONTROLLER_BUTTON_BACK:
				if (!fullscreen)
				{
					fullscreen = true;
					SDL_SetWindowFullscreen(start.window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					start.screen.x = ((start.screen.w / 2) - (start.screen.w / 2));
					start.screen.y = ((start.screen.w / 2) - (start.screen.h / 2));
					SDL_Log("User entered fullscreen . . .");
				}
				else
				{
					fullscreen = false;
					SDL_SetWindowFullscreen(start.window, 0);
					start.screen.x = 0;
					start.screen.y = 0;
					SDL_Log("User exited fullscreen . . .");
				}
				break;
			case SDL_CONTROLLER_BUTTON_START:
				SDL_Log("User closed application . . .");
				*dead = true;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_UP:
				up = true;
				down = false;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
				left = true;
				right = false;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
				down = true;
				up = false;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
				right = true;
				left = false;
				printf("\nright = true\n\n");
				break;
			case SDL_CONTROLLER_BUTTON_A:
				shooting = true;
				break;
			default:
				break;
			}
			break;
		case SDL_CONTROLLERBUTTONUP:
			switch (event.cbutton.button)
			{
			case SDL_CONTROLLER_BUTTON_DPAD_UP:
				up = false;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
				left = false;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
				down = false;
				break;
			case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
				right = false;
				printf("\nright = false\n");
				break;
			default:
				break;
			}
			break;
		case SDL_CONTROLLERAXISMOTION:
			switch (event.caxis.which)
			{
			case SDL_CONTROLLER_AXIS_LEFTX:
			//	if (event.caxis.value > -5000 && event.caxis.value < 5000)
			//	{
			//		left = false;
			//		right = false;	
			//	}				
			//	else if (event.caxis.value > 5000 && event.caxis.value > -5000)
			//	{
			//		right = true;
			//		left = false;
			//	}
			//	else if (event.caxis.value < -5000 && event.caxis.value < 5000)
			//	{
			//		left = true;
			//		right = false;
			//	}
			//	break;
			//case SDL_CONTROLLER_AXIS_LEFTY:  
			//	if (event.caxis.value > -5000 && event.caxis.value < 5000)
			//	{
			//		up = false;
			//		down = false;
			//	}
			//	else if (event.caxis.value > 5000 && event.caxis.value > -5000)
			//	{
			//		up = true;
			//		down = false;
			//	}
			//	else if (event.caxis.value < -5000 && event.caxis.value < 5000)
			//	{
			//		down = true;
			//		up = false;
			//	}
				break;
			case SDL_CONTROLLER_AXIS_RIGHTX:
				break;
			case SDL_CONTROLLER_AXIS_RIGHTY:
				break;
			case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
				break;
			case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
				break;
			}
				break;
		default:
			break;
		}
	}
}

void Input::UpdateGame(Player* player, Startup start, std::vector<Sprite*> spriteList)
{	
	if (player->health < 80)
	{
		spriteList[9]->texture = nullptr;
	}
	if (player->health < 60)
	{
		spriteList[8]->texture = nullptr;
	}
	if (player->health < 40)
	{
		spriteList[7]->texture = nullptr;
	}
	if (player->health < 30)
	{
		spriteList[6]->texture = nullptr;
	}
	if (player->health < 20)
	{
		spriteList[5]->texture = nullptr;
	}
	//Animation
	if (up == false && down == false && left == false && right == false)
	{
		player->playerSource = { 0,0,31,36 };
	}

	if (up == true || down == true || left == true || right == true)
	{
		counter++;

		switch (counter)
		{
		case 0:
			player->playerSource = { 0,0,31,36 };
			break;
		case 4:
			player->playerSource = { 96, 0, 31, 37 };
			break;
		case 8:
			player->playerSource = { 144, 0, 31, 37 };
			break;
		case 12:
			player->playerSource = { 144, 0, 31, 37 };
			break;
		case 16:
			player->playerSource = { 0, 48, 31, 37 };
			break;
		case 20:
			player->playerSource = { 49, 48, 31, 37 };
			break;
		case 24:
			player->playerSource = { 97, 48, 31, 35 };
			break;
		case 28:
			player->playerSource = { 146, 48, 31, 36 };
			break;
		case 32:
			counter = 0;
			break;
		default:
			break;
		}
	}
	
	//Moves reticule
	spriteList[1]->posRect.x = mousex - (spriteList[1]->posRect.w / 2);
	spriteList[1]->posRect.y = mousey - (spriteList[1]->posRect.h / 2 );

	//Rotation
	AngleSprite(player);

	//Movement
	//controller bools
	if (up == true)
	{
		if (player->playerPos.y <= 0)
		{
			up = false;
		}
		else
		{
			player->playerPos.y -= speed;
		}
	}

	if (down == true)
	{
		if (player->playerPos.y >= (start.screen.h - player->playerPos.h))
		{
			down = false;
		}
		else
		{
			player->playerPos.y += speed;
		}		
	}	

	if (left == true)
	{
		if (player->playerPos.x <= 0)
		{
			left = false;
		}
		else
		{
			player->playerPos.x -= speed;
		}		
	}	

	if (right == true)
	{
		if (player->playerPos.x >= (start.screen.w - player->playerPos.w))
		{
			right = false;
		}
		else
		{
			player->playerPos.x += speed;
		}
	}
	//code to handle shooting
	if (shooting == true)
	{
		shooting = false;
		Mix_PlayChannel(-1, shot, 0);
		player->Shoot(start.renderer);
	}
}

void Input::AngleSprite(Player* player)
{
	double dx, dy; 

	dx = (player->playerPos.x + (player->playerPos.w / 2)) - mousex;
	dy = (player->playerPos.y + (player->playerPos.h / 2)) - mousey;

	player->angle = ((atan2(dy, dx) * 180.0000) / 3.1416);
}