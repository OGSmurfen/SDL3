
#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


static SDL_Window* window;
static SDL_Renderer* renderer;
static Uint64 last_time = 0;


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define NUM_POINTS 500
#define MIN_PIXELS_PER_SECOND 30  
#define MAX_PIXELS_PER_SECOND 60 

static SDL_FPoint points[NUM_POINTS];
static float point_speeds[NUM_POINTS];

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
	int i;
	SDL_SetAppMetadata("Moving pts", "1.0", "com.papasmurfie.points");

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Error init SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}
	if (!SDL_CreateWindowAndRenderer("Points", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
		SDL_Log("Error creatin window/renderer: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	for (i = 0; i < SDL_arraysize(points); i++) {
		points[i].x = SDL_randf() * ((float)WINDOW_WIDTH);
		points[i].y = SDL_randf() * ((float)WINDOW_HEIGHT);
		point_speeds[i] = MIN_PIXELS_PER_SECOND + (SDL_randf() * (MAX_PIXELS_PER_SECOND - MIN_PIXELS_PER_SECOND));
	}

	last_time = SDL_GetTicks();

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
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
	const Uint64 now = SDL_GetTicks();
	const float elapsed = ((float)(now - last_time)) / 1000.0f;

	for (int i = 0; i < SDL_arraysize(points); i++) {
		const float distance = elapsed * point_speeds[i];
		points[i].x += distance;
		points[i].y += distance;
		if (points[i].x >= WINDOW_WIDTH || points[i].y >= WINDOW_HEIGHT) {
			if (SDL_rand(2)) {
				points[i].x = SDL_randf() * ((float)WINDOW_WIDTH);
				points[i].y = 0.0f;
			}
			else {
				points[i].x = 0.0f;
				points[i].y = SDL_randf() * ((float)WINDOW_HEIGHT);
			}
			point_speeds[i] = MIN_PIXELS_PER_SECOND + (SDL_randf() * (MAX_PIXELS_PER_SECOND - MIN_PIXELS_PER_SECOND));
		}
	}

	last_time = now;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderPoints(renderer, points, SDL_arraysize(points));

	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

}