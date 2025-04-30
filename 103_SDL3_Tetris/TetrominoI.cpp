#pragma once

#include "TetrominoI.h"

PapaSmurfie::TetrominoI::TetrominoI() : Tetromino(){

	blocks[0] = Block(PapaSmurfieUtil::Color{ 108, 207, 235 });
	blocks[1] = Block(blocks[0].GetX(), blocks[0].GeY() + blocks[0].blockSize, PapaSmurfieUtil::Color{ 108, 207, 235 });
	blocks[2] = Block(blocks[1].GetX(), blocks[1].GeY() + blocks[1].blockSize, PapaSmurfieUtil::Color{ 108, 207, 235 });
	blocks[3] = Block(blocks[2].GetX(), blocks[2].GeY() + blocks[2].blockSize, PapaSmurfieUtil::Color{ 108, 207, 235 });

}