#pragma once
#include "Board.h"
#include <vector>

class BoardBuilder
{
	int dimension;
	std::vector<Stair> _stairs;

public:
	BoardBuilder(int);
	~BoardBuilder();

	const Board build();
	void addStair(int, int);
};

