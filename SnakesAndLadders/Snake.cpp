#include "stdafx.h"
#include "Snake.h"

Snake::Snake(int _begin, int _end)
{
	if (_begin > 0 && _end > 0 && _end < _begin) {
		begin = _begin;
		end = _end;
	}
	else
		throw std::invalid_argument("Values cannot be negative.");
}

const int Snake::getBegin() const {
	return begin;
}
const int Snake::getEnd() const {
	return end;
}
Snake::~Snake()
{
}
