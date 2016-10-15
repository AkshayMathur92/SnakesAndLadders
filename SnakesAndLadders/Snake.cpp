#include "stdafx.h"
#include "Snake.h"

Snake::Snake(int begin, int end)
{
	if (begin > 0 && end > 0 && end < begin) {
		_begin = begin;
		_end = end;
	}
	else
		throw std::invalid_argument("Value cannot be less than 1.");
}

const int Snake::getBegin() const {
	return _begin;
}

const int Snake::getEnd() const {
	return _end;
}

Snake::~Snake()
{
}
