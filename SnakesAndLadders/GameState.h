#pragma once
#include <map>
#include "Player.h"
#include "Board.h"
#include <boost\optional.hpp>

enum class state { NOT_STARTED, IN_PROGRESS, OVER };

class GameState
{
	state _state;
	const Board _board;
	const int _max_pos;
	boost::optional<const Player> _winner;
	std::map<int, int> _playerPositions;

public:
	GameState(Board&, const std::vector<Player>&);
	void update(const Player&, std::tuple<int,int,int>&);
	state getState();
	const Player getWinner();
};