#include "stdafx.h"
#include "Dice.h"
#include <stdlib.h>


Dice::Dice(int timesRollable, int sided)
{
	if (!(timesRollable > 0 && sided > 0))
		throw std::invalid_argument("values must be positive");
	_timesRollable = timesRollable;
	_sided = sided;
	_id = rand();
	_rolled = 1;
	_rollHistory.reserve(8);
}


Dice::~Dice()
{
}

const int Dice::roll()
{
	
	if (_rolled > _timesRollable)
		throw std::logic_error("Dice cannot be rolled anymore");
	_rolled++;
	auto value = rand() % _sided + 1;
	if (value != 6)
		_rolled = _timesRollable + 1;
	_rollHistory.push_back(value);
	return value;
}

const int Dice::getId()
{
	return _id;
}

const std::vector<int>& Dice::getHistory() const
{
	return _rollHistory;
}
