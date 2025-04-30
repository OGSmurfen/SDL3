#include "Tetromino.h"



PapaSmurfie::Tetromino::Tetromino()
{
	
}

void PapaSmurfie::Tetromino::Render(SDL_Renderer* renderer)
{
	for (int i = 0; i < SDL_arraysize(blocks); i++) {
		blocks[i].Render(renderer);
	}
}

void PapaSmurfie::Tetromino::Fall()
{
	for (int i = 0; i < SDL_arraysize(blocks); i++) {
		blocks[i].Fall();
	}
}

void PapaSmurfie::Tetromino::CheckCollisions(const std::vector<PapaSmurfie::Block>& allTetrominos)
{
	for (int i = 0; i < SDL_arraysize(blocks); i++) {
		blocks[i].CheckCollisions(allTetrominos);
	}
}



bool PapaSmurfie::Tetromino::HasFallen()
{
	for (int i = 0; i < SDL_arraysize(blocks); i++) {
		if (blocks[i].HasFallen())
			return true;
	}
	return false;
}

std::array<PapaSmurfie::Block, 4> PapaSmurfie::Tetromino::AllBlocks()
{
	return blocks;
}

void PapaSmurfie::Tetromino::MoveLeft(const std::vector<PapaSmurfie::Block>& allTetrominos)
{
	bool canMove = true;

	for (int i = 0; i < SDL_arraysize(blocks); i++) {
		if (!blocks[i].MoveLeftIfPossible(allTetrominos)) {
			canMove = false;
		}
	}

	if (canMove) {
		for (int i = 0; i < SDL_arraysize(blocks); i++) {
			blocks[i].GetRect()->x -= MOVE_LR_DISTANCE;
		}
	}
}

void PapaSmurfie::Tetromino::MoveRight(const std::vector<PapaSmurfie::Block>& allTetrominos)
{
	bool canMove = true;

	for (int i = 0; i < SDL_arraysize(blocks); i++) {
		if (!blocks[i].MoveRightIfPossible(allTetrominos)) {
			canMove = false;
		}
	}

	if (canMove) {
		for (int i = 0; i < SDL_arraysize(blocks); i++) {
			blocks[i].GetRect()->x += MOVE_LR_DISTANCE;
		}
	}
}
