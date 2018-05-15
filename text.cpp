#include "text.h"

Text::Text()
{

}

Text::Text(SDL_Renderer* renderer)
{
	SDL_Surface *temp;
	SDL_Texture *texture;

	temp = IMG_Load("..\\assets\\fonts\\font.png");
	texture = SDL_CreateTextureFromSurface(renderer, temp);

	if (texture == NULL)
	{
		SDL_Log("Font didn't load because: %s\n", SDL_GetError());
	}
	else
	{
		SDL_Log("Font loaded OK.");
	}
}

void Text::Convert(char* message)
{
	for (int i = 0; i < sizeof(message); i++)
	{
		temp = message[i];
		GetLetter(i);
	}
}

void Text::Write(SDL_Renderer* renderer)
{

}

SDL_Surface* Text::GetLetter(char in)
{

	switch (in)
	{
	case 'a':
	case 'A':
		break;
	case 'b':
	case 'B':
		break;
	case'c':
	case'C':
		break;
	case 'd':
	case 'D':
		break;
	case 'e':
	case 'E':
		break;
	case 'f':
	case 'F':
		break;
	case 'g':
	case 'G':
		break;
	case 'h':
	case 'H':
		break;
	case 'i':
	case 'I':
		break;
	case 'j':
	case 'J':
		break;
	case 'k':
	case 'K':
		break;
	case 'l':
	case 'L':
		break;
	case 'm':
	case 'M':
		break;
	case 'n':
	case 'N':
		break;
	case 'o':
	case 'O':
		break;
	case 'p':
	case 'P':
		break;
	case 'q':
	case 'Q':
		break;
	case 'r':
	case 'R':
		break;
	case 's':
	case 'S':
		break;
	case 't':
	case 'T':
		break;
	case 'u':
	case 'U':
		break;
	case 'v':
	case 'V':
		break;
	case 'w':
	case 'W':
		break;
	case 'x':
	case 'X':
		break;
	case 'y':
	case 'Y':
		break;
	case 'z':
	case 'Z':
		break;
	case '0':
		break;
	case '1':
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	case '7':
		break;
	case '8':
		break;
	case '9':
		break;
	case ' ':

		break;
	default:
		break;
	}
	return Letter;
}