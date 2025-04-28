#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>

namespace PapaSmurfie {
	bool CheckCollision(const SDL_FRect &r1, const SDL_FRect &r2);
}
