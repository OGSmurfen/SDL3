#pragma once

#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_stdinc.h>
#include "Snake.h"
#include "Food.h"
#include "manager.h"

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

static PapaSmurfie::Snake snake;
static PapaSmurfie::Food* food;

float lastTime;
float refreshTime = 0.2f;

int score = 0;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
	SDL_SetAppMetadata("Snake", "1.0", "com.papasmurfie.rectangles");

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Error video init: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	if (!SDL_CreateWindowAndRenderer("Snake", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
		SDL_Log("Error init renderer/video: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	lastTime = SDL_GetTicks() / 1000.0f;

	food = new PapaSmurfie::Food(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 50);

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
	if (event->type == SDL_EVENT_KEY_DOWN) {
		switch (event->key.key) 
		{
		case SDLK_ESCAPE:
			return SDL_APP_SUCCESS;
		case SDLK_W:
			snake.SetMoveDir('W');
			break;
		case SDLK_A:
			snake.SetMoveDir('A');
			break;
		case SDLK_S:
			snake.SetMoveDir('S');
			break;
		case SDLK_D:
			snake.SetMoveDir('D');
			break;
		default:
			break;
		}
		
	}
	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;
	}
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) 
{
	
	const float now = SDL_GetTicks() / 1000.0f;

	

	if (now - refreshTime >= lastTime) {
		snake.MoveSnake();
		lastTime = now;
	}
	

	
	// black for background
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);


	// green for head
	SDL_SetRenderDrawColor(renderer, 50, 168, 82, SDL_ALPHA_OPAQUE);

	// render head
	SDL_RenderFillRect(renderer, snake.GetSnakeHead());

	// yellow for body
	SDL_SetRenderDrawColor(renderer, 219, 196, 20, SDL_ALPHA_OPAQUE);

	std::vector<SDL_FRect> snBody = snake.GetSnakeBody();

	if (PapaSmurfie::CheckCollision(*snake.GetSnakeHead(), *food->GetBody()))
	{
		score++;
		delete food;
		food = nullptr; // redundant but i will leave it here xD
		food = new PapaSmurfie::Food(WINDOW_WIDTH - 50, WINDOW_HEIGHT - 50);

		snake.AddBodyPart();

		refreshTime -= (refreshTime * 0.1f);
	}

	// body is at index after 1
	for (int i = 1; i < snBody.size(); i++) 
	{
		SDL_RenderFillRect(renderer, &snBody.at(i));
	}


	// red for food
	SDL_SetRenderDrawColor(renderer, 250, 0, 17, SDL_ALPHA_OPAQUE);

	if(food != nullptr)
		SDL_RenderFillRect(renderer, food->GetBody());

	// white for score
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	


	SDL_Log("%d", score);

	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
	delete food;
}