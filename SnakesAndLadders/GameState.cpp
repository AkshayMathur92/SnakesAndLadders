#include "stdafx.h"
#include "GameState.h"
#include <iostream>
#include <algorithm>
#include <utility>


GameState::GameState(Board &board, const std::vector<Player> &players) :_max_pos(board.getDimesion() * board.getDimesion()), _board(board)
{
	_state = state::NOT_STARTED;
	std::for_each(players.begin(), players.end(), [&](const Player &player) {
		_playerPositions.insert(std::make_pair( player.getId(), 0));
	});
}

void GameState::update(const Player &player, std::tuple<int,int,int> &moves) {

	if (_state == state::OVER)
		return;
	if (_state == state::NOT_STARTED)
		_state = state::IN_PROGRESS;

	int moves_arr[] = { std::get<0>(moves),std::get<1>(moves) ,std::get<2>(moves) };
	std::for_each(std::begin(moves_arr), std::end(moves_arr), [&](int move) {
		auto new_pos = move + (*_playerPositions.find(player.getId())).second;

		if (new_pos <= _max_pos) {

			new_pos = _board.getNextPosition(new_pos);
			_playerPositions.insert_or_assign(player.getId(), new_pos);

			if (new_pos == _max_pos) {
				_winner =player;
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

const Player GameState::getWinner()
{
	if (_state == state::OVER) {
		return _winner.get();
	}
	else
		throw std::exception("Game if not over. cannot decide winner.");
}
