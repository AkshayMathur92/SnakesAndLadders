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
	const int _max_pos;
	boost::optional<Player> _winner;
	std::map<int, int> _playerPositions;

public:
	GameState(Board&, std::vector<Player>&);
	~GameState();
	void update(Player&, std::vector<int>&);
	state getState();
	Player getWinner();
};