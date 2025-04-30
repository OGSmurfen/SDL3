#pragma once
#include "TetrominoO.h"

PapaSmurfie::TetrominoO::TetrominoO() : Tetromino(){
	blocks[0] = Block(PapaSmurfieUtil::Color{ 211, 227, 32 });
	blocks[1] = Block(blocks[0].GetX() + blocks[0].blockSize, blocks[0].GeY(), PapaSmurfieUtil::Color{ 211, 227, 32 });
	blocks[2] = Block(blocks[0].GetX(), blocks[1].GeY() + blocks[0].blockSize, PapaSmurfieUtil::Color{ 211, 227, 32 });
	blocks[3] = Block(blocks[1].GetX() , blocks[1].GeY() + blocks[1].blockSize, PapaSmurfieUtil::Color{ 211, 227, 32 });
}