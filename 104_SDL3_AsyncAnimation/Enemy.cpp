#include "Enemy.h"

PapaSmurfie::Enemy::Enemy()
{
	int rand = SDL_rand(4);
	switch (rand) {
		case 0:
		{ // spawn enemy from top
			int rand = SDL_rand(WINDOW_WIDTH);
			position = { (float)rand, (float)0 };
		}
			break;
		case 1:
		{ // spawn enemy from bot
			int rand = SDL_rand(WINDOW_WIDTH);
			int other = WINDOW_HEIGHT;
			position = { (float)rand, (float)other - width };
		}
			break;
		case 2:
		{ // spawn from left
			int rand = SDL_rand(WINDOW_HEIGHT);
			position = { (float)0, (float)rand };
		}
			break;
		case 3:
		{ // spawn from right
			int rand = SDL_rand(WINDOW_HEIGHT);
			int other = WINDOW_WIDTH;
			position = { (float)other - width, (float)rand };
		}
			break;
	}
}

void PapaSmurfie::Enemy::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 43, 39, 102, SDL_ALPHA_OPAQUE);
	SDL_FRect rect = { position.x, position.y, width, width };
	SDL_RenderFillRect(renderer, &rect);
}

void PapaSmurfie::Enemy::Move()
{
	//PapaSmurfie::Vector2 playerPos = 
}
