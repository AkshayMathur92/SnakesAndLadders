#include "stdafx.h"
#include "Square.h"
#include <stdexcept>


Square::Square(int _value)
{
	if (_value > 0)
		value = _value;
	else
		throw std::invalid_argument("Value cannot be negative.");
}

const int Square::getValue() const {
	return value;
}

Square::~Square()
{
}

Square Square::operator++()
{
	return Square(value + 1);
}
