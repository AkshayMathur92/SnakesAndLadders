#pragma once
#include "Dice.h"
class DiceFactory
{
	int _sided;
	int _timesRollable;
public:
	DiceFactory(int, int);
	~DiceFactory();
	Dice newDice();
};

