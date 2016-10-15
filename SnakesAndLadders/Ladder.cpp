#include "stdafx.h"
#include "Ladder.h"

Ladder::Ladder(int _begin, int _end)
{
	if (_begin > 0 && _end > 0 && _begin < _end) {
		begin = _begin;
		end = _end;
	}
	else
		throw std::invalid_argument("Values cannot be negative.");

}

const int Ladder::getBegin() const {
	return begin;
}
const int Ladder::getEnd() const {
	return end;
}

Ladder::~Ladder()
{
}
