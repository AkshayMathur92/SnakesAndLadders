#include "stdafx.h"
#include "GameState.h"
#include <iostream>
#include <algorithm>
#include <utility>


GameState::GameState(Board board, std::vector<Player> players):_board(board),_ladders(board.getLadders()),_snakes(board.getSnakes())
{
	_state = state::NOT_STARTED;
	std::for_each(players.begin(), players.end(), [&](Player player) {
		_playerPositions.insert(std::make_pair( player.getId(), 0));
	});
}

GameState::~GameState()
{
}

int GameState::update(Player player, std::vector<int> moves) {

	if (_state == state::OVER)
		return -1;
	if (_state == state::NOT_STARTED)
		_state = state::IN_PROGRESS;

	std::for_each(moves.begin(), moves.end(), [&](int move) {
		auto pos = *_playerPositions.find(player.getId());
		auto new_pos = pos.second + move;

		if (new_pos <= _board.getDimesion() * _board.getDimesion()) {

			auto ladder_itr = std::find_if(_ladders.begin(), _ladders.end(), [&](Ladder ladder) {
				return (ladder.getBegin() == new_pos);
			});
			if (ladder_itr != _ladders.end())
				new_pos = (*ladder_itr).getEnd();

			auto snake_itr = std::find_if(_snakes.begin(), _snakes.end(), [&](Snake snake) {
				return (snake.getBegin() == new_pos);
			});
			if (snake_itr != _snakes.end())
				new_pos = (*snake_itr).getEnd();

			_playerPositions.insert_or_assign(player.getId(), new_pos);

			if (new_pos == _board.getDimesion() * _board.getDimesion()) {
				_winner = player;
				_state = state::OVER;
			}
			//JUST FOR DEBUG PURPOSE
			std::cout << player.getId() << " moved " << move << " to " << new_pos<< std::endl;
		}
	});
	return 0;
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
