#pragma once
#include "GameState.h"
#include "DiceFactory.h"
#include <vector>

class Game
{
	std::vector<Player> _players;
	DiceFactory _diceFactory;
	GameState _gameState;

public:
	Game(Board, DiceFactory, std::vector<Player>);
	~Game();
	void run();
};

