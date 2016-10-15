#pragma once
#include "Board.h"
#include <vector>

class BoardBuilder
{
	int dimension;
	std::vector<Ladder> _ladders;
	std::vector<Snake> _snakes;

public:
	BoardBuilder(int);
	~BoardBuilder();

	const Board build();
	void addStair(int, int);
};

