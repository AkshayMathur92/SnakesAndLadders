#include "stdafx.h"
#include "Player.h"


Player::Player(int id):_id(id)
{
	_fStrategy = [](std::vector<int> &moves) {
		return moves;
	};
}

int Player::getId() const 
{
	return _id;
}

std::tuple<int,int,int> Player::getMoves(std::tuple<int,int,int> &moves)const 
{
	//return _fStrategy(_rollHistory);
	return moves;
}

void Player::setStrategy(strategy newStrategry)
{
	if (newStrategry == nullptr)
		throw std::invalid_argument("Stratergy cannot be null");
	_fStrategy = newStrategry;
}

const Player Player::operator=(const Player & player)const
{
	return Player(player.getId());
}
