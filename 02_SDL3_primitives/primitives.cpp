#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_FPoint points[500];

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
	int i;

	SDL_SetAppMetadata("Example Render Primitives", "1.0", "com.papasmurfie.primitives");

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Could not initizlize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	int gameWX = 1920;
	int gameWY = 1080;

	if (!SDL_CreateWindowAndRenderer("primitives", gameWX, gameWY, 0, &window, &renderer)) {
		SDL_Log("Could not create window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}


	SDL_SetRenderScale(renderer, 2, 2);



	for (int i = 0; i < SDL_arraysize(points); i++) {
		points[i].x = (SDL_randf() * 600.0f) + 100.0f;
		points[i].y = (SDL_randf() * 600.0f) + 100.0f;
	}


	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event *event)
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
	SDL_FRect rect;

	SDL_SetRenderDrawColor(renderer, 50, 168, 82, SDL_ALPHA_OPAQUE); // green
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 49, 45, 161, SDL_ALPHA_OPAQUE); // blue
	rect.x = rect.y = 100;
	rect.w = 400;
	rect.h = 400;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, 199, 24, 56, SDL_ALPHA_OPAQUE); // red
	SDL_RenderLine(renderer, 0, 0, 640, 640);
	SDL_RenderLine(renderer, 0, 640, 640, 0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderPoints(renderer, points, SDL_arraysize(points));


	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

}