#include "stdafx.h"
#include "GameState.h"
#include <iostream>
#include <algorithm>
#include <utility>


GameState::GameState(Board &board, std::vector<Player> &players) :_max_pos(board.getDimesion() * board.getDimesion()), _board(board)
{
	_state = state::NOT_STARTED;
	std::for_each(players.begin(), players.end(), [&](Player player) {
		_playerPositions.insert(std::make_pair( player.getId(), 0));
	});
}

GameState::~GameState()
{
}

void GameState::update(Player &player, std::vector<int> &moves) {

	if (_state == state::OVER)
		return;
	if (_state == state::NOT_STARTED)
		_state = state::IN_PROGRESS;

	std::for_each(moves.begin(), moves.end(), [&](int move) {
		auto new_pos = move + (*_playerPositions.find(player.getId())).second;

		if (new_pos <= _max_pos) {

			new_pos = _board.getNextPosition(new_pos);
			_playerPositions.insert_or_assign(player.getId(), new_pos);

			if (new_pos == _max_pos) {
				_winner = player;
				_state = state::OVER;
			}
			//JUST FOR DEBUG PURPOSE
			//std::cout << player.getId() << " moved " << move << " to " << new_pos<< std::endl;
		}
	});
}

state GameState::getState()
{
	return _state;
}

Player GameState::getWinner()
{
	if (_state == state::OVER) {
		return _winner.get();
	}
	else
		throw std::exception("Game if not over. cannot decide winner.");
}
