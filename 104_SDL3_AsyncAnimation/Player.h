#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
#include <vector>
#include <memory>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_render.h>

#include "GameObject.h"
#include "defines.h"
#include "Vector2.h"

namespace PapaSmurfie {
	class Player : public GameObject{
	public:
		Player();
		void Render(SDL_Renderer* renderer) override;
		void Move(PapaSmurfie::Vector2 mousePos);
		PapaSmurfie::Vector2 GetRifleEnd();
		PapaSmurfie::Vector2 GetPlayerPos();
	private:
		SDL_FRect body;
		PapaSmurfie::Vector2 rifleDirection;
		PapaSmurfie::Vector2 rifleBegin{0, 0};
		PapaSmurfie::Vector2 rifleEnd{ 0,0 };
		float rifleLength = 80.0f;
		int rifleThickness = 10;
		PapaSmurfie::Color bodyColor;
		PapaSmurfie::Color rifleColor;
		float width;
		void RenderBody(SDL_Renderer* renderer);
		void RenderRifle(SDL_Renderer* renderer);
		PapaSmurfie::Vector2 BodyCenter();
		void MoveRifle(PapaSmurfie::Vector2 mousePos);
		void MovePlayer(PapaSmurfie::Vector2 mousePos);
		float movePercentage = 2.0f / 100.0f;
	};

}