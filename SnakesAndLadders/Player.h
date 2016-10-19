#pragma once
#include <vector>
#include <memory>
#include <tuple>
typedef std::vector<int>(*strategy)(std::vector<int>&);

class Player
{
	const int _id;
	strategy _fStrategy;

public:
	Player(int);

	int getId() const ;
	std::tuple<int,int,int> getMoves(std::tuple<int,int,int>&)const;
	void setStrategy(strategy);

	const Player operator=(const Player &player)const ;
};

