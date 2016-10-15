#include "stdafx.h"
#include "DiceFactory.h"


DiceFactory::DiceFactory(int timesRollable,int sided):_sided(sided),_timesRollable(timesRollable)
{
}


DiceFactory::~DiceFactory()
{
}

Dice DiceFactory::newDice()
{
	return Dice(_timesRollable, _sided);
}
