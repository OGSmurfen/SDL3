#include "Bullet.h"

PapaSmurfie::Bullet::Bullet(PapaSmurfie::Vector2 spawnPos, PapaSmurfie::Vector2 aimPos)
{
	position = spawnPos;
	direction = (aimPos - spawnPos).normalized();
}

void PapaSmurfie::Bullet::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 89, 4, 9, SDL_ALPHA_OPAQUE);
	SDL_FRect rect{ position.x - width / 2, position.y - width / 2 , width, width};
	SDL_RenderFillRect(renderer, &rect);
}

void PapaSmurfie::Bullet::Move()
{
	position += direction * speed;
}
