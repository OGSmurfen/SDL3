#include "Player.h"

PapaSmurfie::Player::Player()
{
	width = 50;
	bodyColor = Color{ 207, 235, 52 };
	rifleColor = Color{ 235, 156, 52 };
	body = SDL_FRect{WINDOW_WIDTH / 2 - width / 2, WINDOW_HEIGHT / 2 - width / 2, width, width};
}

void PapaSmurfie::Player::Render(SDL_Renderer* renderer)
{
	RenderRifle(renderer);
	RenderBody(renderer);
}

void PapaSmurfie::Player::Move(PapaSmurfie::Vector2 mousePos)
{
	MoveRifle(mousePos);
	MovePlayer(mousePos);
}

PapaSmurfie::Vector2 PapaSmurfie::Player::GetRifleEnd()
{
	return rifleEnd;
}

PapaSmurfie::Vector2 PapaSmurfie::Player::GetPlayerPos()
{
	PapaSmurfie::Vector2 pos = BodyCenter();
	return pos;
}

void PapaSmurfie::Player::MoveRifle(PapaSmurfie::Vector2 mousePos)
{
	PapaSmurfie::Vector2 playerPos = BodyCenter();

	rifleDirection = (mousePos - playerPos).normalized();

	rifleBegin = playerPos;
	rifleEnd = playerPos + rifleDirection * rifleLength;
}

void PapaSmurfie::Player::MovePlayer(PapaSmurfie::Vector2 mousePos)
{
	PapaSmurfie::Vector2 playerPos = BodyCenter();
	PapaSmurfie::Vector2 moveDir = (mousePos - playerPos);

	body.x += moveDir.x * movePercentage;
	body.y += moveDir.y * movePercentage;
}


void PapaSmurfie::Player::RenderBody(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, bodyColor.r, bodyColor.g, bodyColor.b, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &body);
}

void PapaSmurfie::Player::RenderRifle(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, rifleColor.r, rifleColor.g, rifleColor.b, SDL_ALPHA_OPAQUE);
	
	PapaSmurfie::Vector2 perpendicularVector = PapaSmurfie::Vector2{ -rifleDirection.y, rifleDirection.x};

	for (int i = -rifleThickness; i <= rifleThickness; i++) {
		PapaSmurfie::Vector2 offset = perpendicularVector * i;

		SDL_RenderLine(renderer, 
			rifleBegin.x + offset.x, rifleBegin.y + offset.y,
			rifleEnd.x + offset.x, rifleEnd.y + offset.y);
	}

	//SDL_RenderLine(renderer, rifleBegin.x, rifleBegin.y, rifleEnd.x, rifleEnd.y);
	
}

PapaSmurfie::Vector2 PapaSmurfie::Player::BodyCenter()
{
	float x = body.x + body.w / 2;
	float y = body.y + body.h / 2;
	return PapaSmurfie::Vector2{ x, y };
}

