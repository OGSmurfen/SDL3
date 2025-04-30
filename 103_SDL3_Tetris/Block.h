#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
#include <vector>

#include "GameObject.h"
#include "utility.h"
#include "defines.h"

namespace PapaSmurfie {

	class Block : public GameObject{
	public:
		Block();
		Block(PapaSmurfieUtil::Color newColor);
		Block(float x, float y, PapaSmurfieUtil::Color newColor);
		~Block();
		void Render(SDL_Renderer* renderer) override;
		void Fall();
		bool HasFallen();
		bool MoveLeftIfPossible(const std::vector<PapaSmurfie::Block>& allTetrominos);
		bool MoveRightIfPossible(const std::vector<PapaSmurfie::Block>& allTetrominos);
		void CheckCollisions(const std::vector<PapaSmurfie::Block> &allTetrominos);
		float blockSize = 50.0f;
		float GetX();
		float GeY();
		SDL_FRect* GetRect();
	private:
		SDL_FRect blockRect;
		PapaSmurfieUtil::Color color { 232, 9, 20 }; // red
		bool hasFallen;
	};

}