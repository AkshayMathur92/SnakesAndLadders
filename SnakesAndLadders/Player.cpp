#include "stdafx.h"
#include "Player.h"


Player::Player(int id)
{
	_id = id;
	_fStrategy = [](std::vector<int> &moves) {
		return moves;
	};
	_rollHistory.reserve(256);
}

Player::~Player()
{
}

void Player::rollDice(Dice &dice)
{
	_pDice = dice;
	while (true) {
		try {
			auto value = dice.roll();
			_rollHistory.push_back(value);
			if (value != 6)
				break;
		}
		catch (...) {
			break;
		}
	}
}

const int Player::getId()
{
	return _id;
}

std::vector<int> Player::getMoves()
{
	//return _fStrategy(_rollHistory);
	return _rollHistory;
}

Dice Player::getDice()
{
	if (!_pDice)
		throw std::exception("Player does not have any dice.");
	return *_pDice;
}

void Player::setStrategy(strategy newStrategry)
{
	if (newStrategry == nullptr)
		throw std::invalid_argument("Stratergy cannot be null");
	_fStrategy = newStrategry;
}
