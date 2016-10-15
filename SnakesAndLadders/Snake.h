#pragma once
#include <stdexcept>
#include "Stair.h"

class Snake : protected Stair
{
public:
	Snake(int, int);
	~Snake();
	const int getBegin() const;
	const int getEnd() const;
};

