
#define SDL_MAIN_USE_CALLBACKS 1
#include<SDL3/SDL.h>
#include <SDL3/SDL_main.h>

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{

	if (!SDL_Init(SDL_INIT_VIDEO)){
		SDL_Log("Could not initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("lines", 1920, 1080, 0, &window, &renderer)) {
		SDL_Log("Could not create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	if (event->type == SDL_EVENT_KEY_DOWN) {
		if (event->key.key == SDLK_ESCAPE)
			return SDL_APP_SUCCESS;
	}
	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;
	}
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
	static const SDL_FPoint line_pts[] = {
		{500, 300}, {700, 300}, {700, 300}, {600, 200},
		{600, 200}, {650, 200}, {650, 200}, {500, 100}
	};

	SDL_SetRenderDrawColor(renderer, 202, 241, 252, SDL_ALPHA_OPAQUE); // cyan
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 143, 96, 1, SDL_ALPHA_OPAQUE); // brown

	// tree trunk
	SDL_RenderLine(renderer, 400, 400, 400, 300);
	SDL_RenderLine(renderer, 400, 400, 500, 400);
	SDL_RenderLine(renderer, 500, 400, 500, 300);

	SDL_SetRenderDrawColor(renderer, 13, 102, 24, SDL_ALPHA_OPAQUE); // green

	// tree crown
	// left side
	SDL_RenderLine(renderer, 400, 300, 200, 300);
	SDL_RenderLine(renderer, 200, 300, 300, 200);
	SDL_RenderLine(renderer, 300, 200, 250, 200);
	SDL_RenderLine(renderer, 250, 200, 400, 100);
	// right side using one batch
	SDL_RenderLines(renderer, line_pts, SDL_arraysize(line_pts));
	
	// bonus mid line 
	SDL_RenderLine(renderer, 400, 300, 500, 300);

	// star on top of tree
	for (int i = 0; i < 360; i++) {
		const float size = 50.0f;
		const float x = 450.0f;
		const float y = 100.0f - (size / 2.0f);
		SDL_SetRenderDrawColor(renderer, SDL_rand(256), SDL_rand(256), SDL_rand(256), SDL_ALPHA_OPAQUE);
		SDL_RenderLine(renderer, x, y, x + SDL_sinf((float)i)*size, y + SDL_cosf((float)i)*size);
	}



	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

}