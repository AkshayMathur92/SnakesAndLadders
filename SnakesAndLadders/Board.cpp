#include "stdafx.h"
#include "Board.h"
#include <numeric>

Board::Board():squares(BOARD_DIMESION * BOARD_DIMESION,Square(1))
{
	std::iota(squares.begin(), squares.end(), Square(1));
}

void Board::addSnake(int _begin, int _end) {
	if (_begin > _end && _begin <= BOARD_DIMESION * BOARD_DIMESION) {
		try {
			snakes.push_back(Snake(_begin, _end));
		}
		catch (std::invalid_argument ex) {
			throw ex;
		}
	}
}

void Board::addLadder(int _begin, int _end) {
	if (_begin < _end && _end <= BOARD_DIMESION * BOARD_DIMESION) {
		try {
			ladders.push_back(Ladder(_begin, _end));
		}
		catch (std::invalid_argument ex) {
			throw ex;
		}
	}
}

const std::vector<Ladder> Board::getLadders() const {
	return const_cast<std::vector<Ladder>&>(ladders);
}

const std::vector<Snake> Board::getSnakes() const {
	return const_cast<std::vector<Snake>&>(snakes);
}

Board::~Board()
{
}
