#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>

class Text {
public:
	Text();
	Text(SDL_Renderer* renderer);
	void Write(SDL_Renderer* renderer);
	void Convert(char* message);
	SDL_Surface* GetLetter(char in);
	SDL_Surface* Letter;
	SDL_Texture* output;

	//display text
	SDL_Texture* outMessage;
	char temp;
private:
};