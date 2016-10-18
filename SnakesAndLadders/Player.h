#pragma once
#include "Dice.h"
#include <vector>
#include <memory>
#include <boost\optional.hpp>
typedef std::vector<int>(*strategy)(std::vector<int>&);

class Player
{
	int _id;
	boost::optional<Dice> _pDice;
	std::vector<int> _rollHistory;
	strategy _fStrategy;

public:
	Player(int);
	~Player();

	void rollDice(Dice&);
	const int getId();
	std::vector<int> getMoves();
	Dice getDice();
	void setStrategy(strategy);
};

