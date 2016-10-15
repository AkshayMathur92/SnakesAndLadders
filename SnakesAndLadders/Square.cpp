#include "stdafx.h"
#include "Square.h"
#include <stdexcept>


Square::Square(int value)
{
	if (value > -1)
		_value = value;
	else
		throw std::invalid_argument("Value cannot be negative.");
}

const int Square::getValue() const {
	return _value;
}

Square::~Square()
{
}

Square Square::operator++()
{
	return Square(_value + 1);
}
