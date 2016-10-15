#include "stdafx.h"
#include "Player.h"


Player::Player(int id)
{
	_id = id;
	_fStrategy = [](std::vector<int> moves) {
		return moves;
	};
}

Player::~Player()
{
}

void Player::rollDice(Dice dice)
{
	_pDice = dice;
	while (true) {
		try {
			_rollHistory.push_back(dice.roll());
		}
		catch (...) {
			break;
		}
	}
}

const int Player::getId()
{
	return 0;
}

std::vector<int> Player::getMoves()
{
	return _fStrategy(_rollHistory);
}

Dice Player::getDice()
{
	if (_pDice)
		throw std::exception("Player does not have any dice.");
	return *_pDice;
}

void Player::setStrategy(strategy newStrategry)
{
	if (newStrategry == nullptr)
		throw std::invalid_argument("Stratergy cannot be null");
	_fStrategy = newStrategry;
}
