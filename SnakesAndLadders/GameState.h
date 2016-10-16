#pragma once
#include <map>
#include "Player.h"
#include "Board.h"
#include <boost\optional.hpp>
#include <boost\ptr_container\ptr_vector.hpp>

enum class state { NOT_STARTED, IN_PROGRESS, OVER };

class GameState
{
	state _state;
	std::map<int,int>_stairs;
	const int _dimension;
	boost::optional<Player> _winner;
	std::map<int, int> _playerPositions;

public:
	GameState(Board, std::vector<Player>);
	~GameState();
	void update(Player, std::vector<int>);
	state getState();
	Player getWinner();
};