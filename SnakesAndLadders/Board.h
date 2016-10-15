#pragma once
#include "Square.h"
#include "Ladder.h"
#include "Snake.h"
#include <vector>

#ifndef BOARD_DIMENSION
#define BOARD_DIMESION 10
#endif // !BOARD_DIMENSION

class Board
{
	std::vector<Square> squares;
	std::vector<Ladder> ladders;
	std::vector<Snake> snakes;
	
public:
	Board();
	~Board();

	void addLadder(int, int);
	void addSnake(int, int);

	const std::vector<Ladder> getLadders() const;

	const std::vector<Snake> getSnakes() const;
};