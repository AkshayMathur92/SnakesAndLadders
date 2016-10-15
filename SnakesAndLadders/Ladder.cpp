#include "stdafx.h"
#include "Ladder.h"

Ladder::Ladder(int begin, int end)
{
	if (begin > 0 && end > 0 && begin < end) {
		_begin = begin;
		_end = end;
	}
	else
		throw std::invalid_argument("Value cannot be less than 1.");
}

const int Ladder::getBegin() const {
	return _begin;
}

const int Ladder::getEnd() const {
	return _end;
}

Ladder::~Ladder()
{
}
