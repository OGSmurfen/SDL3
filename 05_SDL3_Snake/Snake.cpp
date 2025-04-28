#pragma once
#include "Snake.h"

namespace PapaSmurfie {


	Snake::Snake()
	{
		moveDir = 'D';
		width = 50;
		initialCoords = 100;
		moveDistance = width;

		//head
		snakeBody.push_back({ initialCoords, initialCoords, width, width });
		//snakeHead = { initialCoords, initialCoords, width, width };

		snakeBody.push_back({ snakeBody.at(0).x - width, snakeBody.at(0).y, width, width});

		snakePreviousBody = snakeBody;
	}

	const SDL_FRect* Snake::GetSnakeHead() const
	{
		return &snakeBody.at(0);
	}

	const std::vector<SDL_FRect> Snake::GetSnakeBody() const
	{
		return snakeBody;
	}

	void Snake::MoveSnake()
	{
		for(int i = 0; i < snakeBody.size(); i++)
		{
			if (i == 0) 
			{
				switch (moveDir)
				{
				case 'W':
				{
					snakeBody.at(i).y -= moveDistance;
				}
				break;
				case 'A':
				{
					snakeBody.at(i).x -= moveDistance;
				}
				break;
				case 'S':
				{
					snakeBody.at(i).y += moveDistance;
				}
				break;
				case 'D':
				{
					snakeBody.at(i).x += moveDistance;
				}
				break;
				}
			}
			else
			{
				snakeBody.at(i) = snakePreviousBody.at(i - 1);
			}
			
		}
		snakePreviousBody = snakeBody;
	}

	void Snake::SetMoveDir(char md)
	{
		moveDir = md;
	}

	int Snake::GetSnakeLength()
	{
		int l = SDL_arraysize(snakeBody);
		return l;
	}

	void Snake::AddBodyPart()
	{
		snakeBody.push_back(SDL_FRect{
			snakeBody.at(snakeBody.size() - 1)
			});
	}



	

}