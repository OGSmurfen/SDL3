#pragma once

#include "Block.h"

PapaSmurfie::Block::Block()
{
	hasFallen = false;
	blockRect = { (float)WINDOW_WIDTH / 2 - blockSize / 2, 0, blockSize, blockSize };
}

PapaSmurfie::Block::Block(PapaSmurfieUtil::Color newColor)
{
	color = newColor;
	hasFallen = false;
	blockRect = { (float)WINDOW_WIDTH / 2 - blockSize / 2, 0, blockSize, blockSize };
}

PapaSmurfie::Block::Block(float x, float y, PapaSmurfieUtil::Color newColor)
{
	color = newColor;
	hasFallen = false;
	float blockSize = 50.0f;
	blockRect = { x, y, blockSize, blockSize };
}


PapaSmurfie::Block::~Block()
{
}

void PapaSmurfie::Block::Render(SDL_Renderer* const renderer)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &blockRect);
}

void PapaSmurfie::Block::Fall()
{
	if(!hasFallen)
		blockRect.y += FALL_DISTANCE;

	//SDL_Log("%d", hasFallen);

	if (blockRect.y + blockRect.h + FALL_DISTANCE > WINDOW_HEIGHT) {
		hasFallen = true;
	}
}

bool PapaSmurfie::Block::HasFallen()
{
	return hasFallen;
}

bool PapaSmurfie::Block::MoveLeftIfPossible(const std::vector<PapaSmurfie::Block>& allTetrominos)
{
	for (int i = 0; i < allTetrominos.size(); i++) {
		if (blockRect.y + blockRect.h >= allTetrominos.at(i).blockRect.y
			 && blockRect.y <= allTetrominos.at(i).blockRect.y + allTetrominos.at(i).blockRect.h)
			if (blockRect.x + blockRect.w + MOVE_LR_DISTANCE> allTetrominos.at(i).blockRect.x
				&& blockRect.x - MOVE_LR_DISTANCE < allTetrominos.at(i).blockRect.x + allTetrominos.at(i).blockRect.w)
				return false;
	}
	//blockRect.x -= MOVE_LR_DISTANCE;
	return true;
}

bool PapaSmurfie::Block::MoveRightIfPossible(const std::vector<PapaSmurfie::Block>& allTetrominos)
{
	for (int i = 0; i < allTetrominos.size(); i++) {
		if (blockRect.y + blockRect.h >= allTetrominos.at(i).blockRect.y
			&& blockRect.y <= allTetrominos.at(i).blockRect.y + allTetrominos.at(i).blockRect.h)
			if (blockRect.x + blockRect.w + MOVE_LR_DISTANCE > allTetrominos.at(i).blockRect.x
				&& blockRect.x - MOVE_LR_DISTANCE< allTetrominos.at(i).blockRect.x + allTetrominos.at(i).blockRect.w)
				return false;
	}
	//blockRect.x += MOVE_LR_DISTANCE;
	return true;
}


void PapaSmurfie::Block::CheckCollisions(const std::vector<PapaSmurfie::Block> &allTetrominos)
{
	for (int i = 0; i < allTetrominos.size(); i++) {
		// appartenlty you can access the private properties of other objects of the same class
		if (blockRect.y + blockRect.h >= allTetrominos.at(i).blockRect.y
			&& blockRect.y <= allTetrominos.at(i).blockRect.y + allTetrominos.at(i).blockRect.h) {
			if(blockRect.x + blockRect.w > allTetrominos.at(i).blockRect.x &&
				blockRect.x < allTetrominos.at(i).blockRect.x + allTetrominos.at(i).blockRect.w)
			this->hasFallen = true;
		}
	}
	
}

float PapaSmurfie::Block::GetX()
{
	return blockRect.x;
}

float PapaSmurfie::Block::GeY()
{
	return blockRect.y;
}

SDL_FRect* PapaSmurfie::Block::GetRect()
{
	return &blockRect;
}



