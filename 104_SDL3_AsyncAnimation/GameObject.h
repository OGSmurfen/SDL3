#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
#include <vector>
#include <memory>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_render.h>

namespace PapaSmurfie {
	class GameObject {
	public:
		virtual void Render(SDL_Renderer *renderer) = 0;
	};
}