
#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

// DO A MATRIX GAME !!!!!!!!

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
	SDL_SetAppMetadata("Example Renderer Clear", "1.0", "com.papasmurfie.renderer-clear");

	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Could not initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("examples/renderer/clear", 800, 600, SDL_WINDOW_FULLSCREEN, &window, &renderer))
	{
		SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appState, SDL_Event *event)
{
	if (event->type == SDL_EVENT_KEY_DOWN)
	{
		if (event->key.key == SDLK_ESCAPE)
			return SDL_APP_SUCCESS;
	}
	if (event->type == SDL_EVENT_QUIT)
	{
		return SDL_APP_SUCCESS;
	}
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) 
{
	const double now = ((double)SDL_GetTicks()) / 1000.0; // convert from ms to s

	const float red = (float)(0.5 + 0.5 * SDL_sin(now));
	const float green = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
	const float blue = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));

	SDL_SetRenderDrawColorFloat(renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT);  /* new color, full alpha. */

	/* clear the window to the draw color. */
	SDL_RenderClear(renderer);

	/* put the newly-cleared rendering on the screen. */
	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult appresult)
{
	// SLD will clean the window/renderer
}