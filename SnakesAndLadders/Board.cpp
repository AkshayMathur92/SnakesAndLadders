#include "stdafx.h"
#include "Board.h"
#include <numeric>

Board::Board(int dimension, std::vector<Ladder> &ladders, std::vector<Snake> &snakes):_squares(dimension * dimension,Square(1))
{
	if (dimension > 0)
		_dimension = dimension;
	else
		throw std::invalid_argument("Dimension cannot be less than 1");

	std::copy(ladders.begin(), ladders.end(),_ladders.begin());
	std::copy(snakes.begin(), snakes.end(), _snakes.begin());
	std::iota(_squares.begin(), _squares.end(), Square(1));
}

const std::vector<Ladder> Board::getLadders() const {
	return const_cast<std::vector<Ladder>&>(_ladders);
}

const std::vector<Snake> Board::getSnakes() const {
	return const_cast<std::vector<Snake>&>(_snakes);
}

const int Board::getDimesion()
{
	return _dimension;
}

Board::~Board()
{
}
