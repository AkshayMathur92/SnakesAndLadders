#pragma once
#include <stdexcept>
#include "Stair.h"

class Ladder : protected Stair
{
public:
	Ladder(int, int);
	~Ladder();
	const int getBegin() const;
	const int getEnd() const;
};

