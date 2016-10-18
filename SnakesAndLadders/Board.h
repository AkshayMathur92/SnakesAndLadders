#pragma once
#include "Stair.h"
#include <vector>


class Board
{
	int _dimension;
	std::vector<Stair> _stairs;
	
public:
	Board(int, std::vector<Stair>&);
	~Board();
	const int getNextPosition(int)const;
	const int getDimesion();
};