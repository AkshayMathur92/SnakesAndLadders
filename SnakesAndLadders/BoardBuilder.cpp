#include "stdafx.h"
#include "BoardBuilder.h"
#include <algorithm>

BoardBuilder::BoardBuilder(int dimesion)
{
	if (dimesion > 1)
		dimension = dimesion;
	else
		throw std::invalid_argument("Dimesion must be greater than 1");
}

BoardBuilder::~BoardBuilder()
{
}

const Board BoardBuilder::build()
{
	return Board(dimension,_stairs);
}

void BoardBuilder::addStair(int begin, int end)
{
	if (begin > 0 && end > 0 && begin <= dimension * dimension && end <= dimension * dimension) {
		if (std::abs(begin - end) > dimension) {
			if (end > begin)
				_stairs.push_back(Stair(begin, end));
		}
		else
			throw std::invalid_argument("Length of stair must be smaller than dimession of board");
	}
	else
		throw std::invalid_argument("Values should be greater than 1 and less than" + dimension * dimension);
}

