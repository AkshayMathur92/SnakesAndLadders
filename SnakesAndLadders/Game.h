#pragma once
#include "GameState.h"
#include <vector>

class Game
{
	std::vector<Player> _players;
	Dice _dice;
	GameState _gameState;

public:
	Game(Board, Dice, std::vector<Player>);
	~Game();
};

