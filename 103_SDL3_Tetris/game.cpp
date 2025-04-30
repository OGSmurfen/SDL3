#pragma once

#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
#include <vector>
#include <memory>

#include "GameObject.h"
#include "Block.h"
#include "defines.h"
#include "Tetromino.h"
#include "TetrominoL.h"
#include "TetrominoZ.h"
#include "TetrominoI.h"
#include "TetrominoO.h"

void PlaceCurrentTetrominoAndCreateNew();
void RenderPlacedTetros();
PapaSmurfie::Tetromino* CreateRandomTetromino();

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;


PapaSmurfie::Tetromino* currentTetromino;
std::vector<PapaSmurfie::Block> allTetrominosAsBlocks;

float lastTime;
float refreshTime = 1.0f/60.0f;

int score = 0;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
	SDL_SetAppMetadata("Tetris", "1.0", "com.papasmurfie.tetris");

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Error video init: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	//currentTetromino = new PapaSmurfie::Block();
	currentTetromino = new PapaSmurfie::TetrominoL();

	if (!SDL_CreateWindowAndRenderer("Tetris", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
		SDL_Log("Error init renderer/video: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	lastTime = SDL_GetTicks() / 1000.0f;


	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	if (event->type == SDL_EVENT_KEY_DOWN) {
		switch (event->key.key)
		{
		case SDLK_ESCAPE:
			return SDL_APP_SUCCESS;
		case SDLK_W:
			break;
		case SDLK_A:
		case SDLK_LEFT:
			if(currentTetromino != nullptr)
				currentTetromino->MoveLeft(allTetrominosAsBlocks);
			break;
		case SDLK_S:
			break;
		case SDLK_D:
		case SDLK_RIGHT:
			if (currentTetromino != nullptr)
				currentTetromino->MoveRight(allTetrominosAsBlocks);
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

SDL_AppResult SDL_AppIterate(void* appstate)
{
	float now = SDL_GetTicks() / 1000.0f;

	if (lastTime + refreshTime < now) {
		lastTime = now;

		if (currentTetromino != nullptr) {
			currentTetromino->Fall();
			currentTetromino->CheckCollisions(allTetrominosAsBlocks);
		}
			
	}

	PlaceCurrentTetrominoAndCreateNew();

	SDL_SetRenderDrawColor(renderer, 111, 143, 120, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	

	if(currentTetromino != nullptr)
		currentTetromino->Render(renderer);


	RenderPlacedTetros();

	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

void PlaceCurrentTetrominoAndCreateNew() {
	if (currentTetromino != nullptr && currentTetromino->HasFallen()) {
		std::array<PapaSmurfie::Block, 4> cTBlocks = currentTetromino->AllBlocks();
		for (int i = 0; i < cTBlocks.size(); i++) {
			allTetrominosAsBlocks.push_back(cTBlocks[i]);
		}

		delete currentTetromino;
		currentTetromino = CreateRandomTetromino();
	}
}

void RenderPlacedTetros() {
	for (int i = 0; i < allTetrominosAsBlocks.size(); i++) {
		allTetrominosAsBlocks.at(i).Render(renderer);
	}
}

PapaSmurfie::Tetromino* CreateRandomTetromino() {
	int rand = SDL_rand(4);
	switch (rand) {
	case 0:
		return new PapaSmurfie::TetrominoZ();
	case 1:
		return new PapaSmurfie::TetrominoL();
	case 2:
		return new PapaSmurfie::TetrominoI();
	case 3:
		return new PapaSmurfie::TetrominoO();
	}
}


void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
	delete currentTetromino;
}