#pragma once
#include "TetrominoZ.h"

PapaSmurfie::TetrominoZ::TetrominoZ() : Tetromino(){
	blocks[0] = Block(PapaSmurfieUtil::Color{ 232, 9, 20 });
	blocks[1] = Block(blocks[0].GetX() + blocks[0].blockSize, blocks[0].GeY(), PapaSmurfieUtil::Color { 232, 9, 20 });
	blocks[2] = Block(blocks[1].GetX(), blocks[1].GeY() + blocks[2].blockSize, PapaSmurfieUtil::Color { 232, 9, 20 });
	blocks[3] = Block(blocks[2].GetX() + blocks[2].blockSize, blocks[2].GeY(), PapaSmurfieUtil::Color { 232, 9, 20 });
}