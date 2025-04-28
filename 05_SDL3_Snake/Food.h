#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>


namespace PapaSmurfie {

	class Food {

	public:
		Food(float windowW, float windowH);
		SDL_FRect* GetBody();
	private:
		SDL_FRect body;
		float width;

	};

}