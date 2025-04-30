#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
#include <vector>
#include <array>

#include "GameObject.h"
#include "utility.h"
#include "defines.h"
#include "Block.h"


namespace PapaSmurfie {

	class Tetromino : public GameObject{

	public:
		Tetromino();
		void Render(SDL_Renderer* renderer) override;
		void Fall();
		void CheckCollisions(const std::vector<PapaSmurfie::Block>& allTetrominos);
		void MoveLeft(const std::vector<PapaSmurfie::Block>& allTetrominos);
		void MoveRight(const std::vector<PapaSmurfie::Block>& allTetrominos);
		bool HasFallen();
		std::array<Block, 4> AllBlocks();
	protected:
		std::array<Block, 4> blocks;
		bool hasFallen = false;
	private:

	};

}