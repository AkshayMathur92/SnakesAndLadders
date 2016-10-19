#include "stdafx.h"
#include "Board.h"
#include <algorithm>
Board::Board(int dimension, std::vector<Stair> &stairs):_stairs(stairs)
{
	if (dimension > 0)
		_dimension = dimension;
	else
		throw std::invalid_argument("Dimension cannot be less than 1");
}

const int Board::getDimesion()
{
	return _dimension;
}

const int Board::getNextPosition(int pos) const {
	auto new_pos_itr = std::find_if(_stairs.begin(), _stairs.end(), [pos](Stair stair) {
		return stair.getBegin() == pos;
	});
	if (new_pos_itr != _stairs.end())
		return new_pos_itr->getEnd();
	return pos;
}