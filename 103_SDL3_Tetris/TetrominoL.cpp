#include "TetrominoL.h"

PapaSmurfie::TetrominoL::TetrominoL() : Tetromino()
{
	blocks[0] = Block(PapaSmurfieUtil::Color{ 245, 161, 66 });
	blocks[1] = Block(blocks[0].GetX(), blocks[0].GeY() + blocks[0].blockSize, PapaSmurfieUtil::Color{ 245, 161, 66 });
	blocks[2] = Block(blocks[1].GetX(), blocks[1].GeY() + blocks[2].blockSize, PapaSmurfieUtil::Color{ 245, 161, 66 });
	blocks[3] = Block(blocks[2].GetX() + blocks[2].blockSize, blocks[2].GeY(), PapaSmurfieUtil::Color{ 245, 161, 66 });
}
