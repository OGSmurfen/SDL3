#include "Food.h"

PapaSmurfie::Food::Food(float windowW, float windowH)
{
	width = 50;

	Sint32 x = SDL_rand(windowW);
	Sint32 y = SDL_rand(windowH);

	body = { (float)x, (float)y, width, width };

}

SDL_FRect* PapaSmurfie::Food::GetBody()
{
	return &body;
}
