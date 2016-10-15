#pragma once
#include "Ladder.h"
class Snake
{
	int begin;
	int end;
public:
	Snake(int, int);
	~Snake();
	const int getBegin() const;
	const int getEnd() const;
};

