#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <vector>

namespace PapaSmurfie {

	class Snake {
	public:
		Snake();
		const SDL_FRect* GetSnakeHead() const;
		const std::vector<SDL_FRect> GetSnakeBody() const;
		void MoveSnake();
		void SetMoveDir(char md);
		int GetSnakeLength();
		void AddBodyPart();
	private:
		char moveDir;
		float width;
		float initialCoords;
		float moveDistance;
		std::vector<SDL_FRect> snakeBody;
		std::vector<SDL_FRect> snakePreviousBody;
	};

}