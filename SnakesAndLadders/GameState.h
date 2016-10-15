#pragma once
#include <map>
#include "Player.h"
#include "Board.h"
#include <boost\optional.hpp>

enum class state { NOT_STARTED, IN_PROGRESS, OVER };

class GameState
{
	state _state;
	Board _board;
	boost::optional<Player> _winner;
	std::map<Player, Square> _playerPositions;

public:
	GameState(Board, std::vector<Player>);
	~GameState();
	int update(Player, std::vector<int>);
	state getState();
	Player getWinner();
};