#pragma once
#include "Stair.h"
#include <vector>


class Board
{
	//TODO const
	int _dimension;
	const std::vector<Stair> _stairs;
	
public:
	Board(int, std::vector<Stair>&);
	int getNextPosition(int)const;
	int getDimesion() const;
};