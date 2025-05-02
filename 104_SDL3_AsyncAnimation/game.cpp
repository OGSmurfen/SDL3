#pragma once

#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
#include <vector>
#include <memory>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_render.h>
#include <iostream>

#include "defines.h"
#include "GameObject.h"
#include "Player.h"
#include "Vector2.h"
#include "Bullet.h"
#include "Enemy.h"


static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

PapaSmurfie::Player* player;
std::vector<PapaSmurfie::Bullet> bullets;
std::vector<PapaSmurfie::Enemy> enemies;

float lastTime;
float refreshTime = 1.0f / 60.0f;
float lastShotTime;
float shootTime = 0.7f;
float lastClearTime;
float clearBulletTime = 3.5f;

int score = 0;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
	SDL_SetAppMetadata("KillerMachine", "1.0", "com.papasmurfie.KillerMachine");

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Error video init: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	

	if (!SDL_CreateWindowAndRenderer("KillerMachine", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
		SDL_Log("Error init renderer/video: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	lastTime = SDL_GetTicks() / 1000.0f;
	lastShotTime = SDL_GetTicks() / 1000.0f;
	lastClearTime = SDL_GetTicks() / 1000.0f;

	player = new PapaSmurfie::Player();


	for (int i = 0; i < 100; i++) {
		enemies.push_back(PapaSmurfie::Enemy());
	}

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
			break;
		case SDLK_S:
			break;
		case SDLK_D:
		case SDLK_RIGHT:
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


	float mouseX, mouseY;
	SDL_MouseButtonFlags mouseBtnFlags = SDL_GetMouseState(&mouseX, &mouseY);
	bool isLBtnPressed = mouseBtnFlags & SDL_BUTTON_LEFT;
	//SDL_Log("mouseX: %.2f; mouseY: %.2f; lBtnPress: %d", mouseX, mouseY, isLBtnPressed);

	if (lastTime + refreshTime < now) {
		lastTime = now;

		player->Move(PapaSmurfie::Vector2{mouseX, mouseY});

		for (int i = 0; i < bullets.size(); i++) {
			bullets[i].Move();
		}

		if (isLBtnPressed && (lastShotTime + shootTime < now)) {
			lastShotTime = now;
			PapaSmurfie::Bullet bullet(player->GetRifleEnd(), PapaSmurfie::Vector2{mouseX, mouseY});
			bullets.push_back(bullet);
		}
		if (lastClearTime + clearBulletTime < now) {
			lastClearTime = now;
			if (!bullets.empty()) {
				bullets.erase(bullets.begin());
			}
		}
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i].Move();
		}
	}

	SDL_SetRenderDrawColor(renderer, 111, 143, 120, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].Render(renderer);
	}
	
	player->Render(renderer);

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].Render(renderer);
	}

	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}



void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
	delete player;
}