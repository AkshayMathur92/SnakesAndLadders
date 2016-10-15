#pragma once
#include <map>
#include "Player.h"
#include "Board.h"
#include <boost\optional.hpp>

enum class state { NOT_STARTED, IN_PROGRESS, OVER };

class GameState
{
	state _state;
	std::vector<Ladder>_ladders;
	std::vector<Snake>_snakes;
	Board _board;
	boost::optional<Player> _winner;
	std::map<int, int> _playerPositions;

public:
	GameState(Board, std::vector<Player>);
	~GameState();
	int update(Player, std::vector<int>);
	state getState();
	Player getWinner();
};