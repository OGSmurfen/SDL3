#pragma once


#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>

namespace PapaSmurfie {


	class GameObject {

	public:
		virtual void Render(SDL_Renderer* renderer) = 0;

		virtual ~GameObject() = default;
	};

}
