#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
#include <vector>

#include "GameObject.h"
#include "utility.h"
#include "defines.h"
#include "Block.h"
#include "Tetromino.h"

namespace PapaSmurfie {

	class TetrominoO : public Tetromino{

	public:
		TetrominoO();
	};
}