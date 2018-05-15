#include "sprite.h"

Sprite::Sprite()
{

}

Sprite::Sprite(std::string tName, std::vector<float>tSize, std::vector<float>tPosition, int tType, SDL_Renderer *renderer)
{
	name = tName;
	size = tSize;
	position = tPosition;
	type = tType;
	angle = 0;

	//passed to renderer
	texture = loadTexture(tType, renderer);
	posRect.w = size[0];
	posRect.h = size[1];
	posRect.x = position[0];
	posRect.y = position[1];

	sourceRect.w = 40;
	sourceRect.h = 40;
	sourceRect.x = 0;
	sourceRect.y = 0;
}

SDL_Texture* Sprite::loadTexture(int type, SDL_Renderer *renderer)
{
	SDL_Surface *temp;
	SDL_Texture *texture;

	//image locations
	char* fl00r = "..\\assets\\sprites\\floor.png";
	char* cursor = "..\\assets\\sprites\\misc.png";
	char* splash = "..\\assets\\sprites\\splash1.png";
	char* death = "..\\assets\\sprites\\end.png";
	char* health = "..\\assets\\sprites\\health.png";
	char* bar = "..\\assets\\sprites\\bar.png";

	switch (type)
	{
	case 0:
		temp = IMG_Load(splash);
		SDL_Log("Splash loaded OK.");
		break;
	case 1:
		temp = IMG_Load(cursor);
		SDL_Log("Cursor loaded OK.");
		break;
	case 2:
		temp = IMG_Load(fl00r);
		SDL_Log("Floor loaded OK.");
		break;
	case 3:
		temp = IMG_Load(death);
		SDL_Log("Dead loaded OK.");
		break;
	case 4:
		temp = IMG_Load(health);
		SDL_Log("Health loaded OK.");
		break;
	case 5:
		temp = IMG_Load(bar);
		SDL_Log("Bar loaded OK.");
	default:
		SDL_Log("Image didn't load because: %s\n", SDL_GetError());
		break;
	}

	texture = SDL_CreateTextureFromSurface(renderer, temp);

	if (texture == NULL)
	{
		SDL_Log("Texture didn't load because: %s\n", SDL_GetError());
	}
	else
	{
		SDL_Log("Texture loaded OK.");
	}

	return texture;
}

Sprite::~Sprite()
{

}

