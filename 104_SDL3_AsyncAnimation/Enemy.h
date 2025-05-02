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
	class Enemy : public GameObject{
	public:
		Enemy();
		void Render(SDL_Renderer* renderer) override;
		void Move();
	private:
		PapaSmurfie::Vector2 position;
		float width = 80.0f;

	};
}