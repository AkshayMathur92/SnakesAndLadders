#pragma once
#include <vector>
class Dice
{
	int _id;
	int _sided;
	int _timesRollable;
	int _rolled;
	std::vector<int> _rollHistory;

public:
	Dice(int,int);
	~Dice();
	const int roll();
	const int getId();
	const std::vector<int>& getHistory() const;
};

