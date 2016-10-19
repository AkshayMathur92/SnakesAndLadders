#pragma once
#include "GameState.h"
#include "BufferedDice.h"
#include <vector>

class Game
{
	const std::vector<Player> _players;
	BufferedDice& _dice;
	GameState _gameState;

public:
	Game( Board&, BufferedDice&, const std::vector<Player>&);
	void run();
};

