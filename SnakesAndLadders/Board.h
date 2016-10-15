#pragma once
#include "Square.h"
#include "Ladder.h"
#include "Snake.h"
#include <vector>


class Board
{
	int _dimension;
	std::vector<Square> _squares;
	std::vector<Ladder> _ladders;
	std::vector<Snake> _snakes;
	
public:
	Board(int, std::vector<Ladder>&, std::vector<Snake>&);
	~Board();

	const std::vector<Ladder> getLadders() const;
	const std::vector<Snake> getSnakes() const;
	const int getDimesion();
};