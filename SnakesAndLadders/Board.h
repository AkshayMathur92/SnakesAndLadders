#pragma once
#include "Stair.h"
#include <vector>


class Board
{
	//TODO const
	int _dimension;
	std::vector<Stair> _stairs;
	
public:
	Board(int, std::vector<Stair>&);
	const int getNextPosition(int)const;
	const int getDimesion();
};