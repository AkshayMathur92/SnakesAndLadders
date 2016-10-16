#include "stdafx.h"
#include "GameState.h"
#include <iostream>
#include <algorithm>
#include <utility>


GameState::GameState(Board board, std::vector<Player> players):_dimension(board.getDimesion())
{
	_state = state::NOT_STARTED;
	std::for_each(players.begin(), players.end(), [&](Player player) {
		_playerPositions.insert(std::make_pair( player.getId(), 0));
	});
	auto ladders = board.getLadders();
	std::for_each(ladders.begin(), ladders.end(), [&](Ladder ladder) {
		_stairs.insert(std::make_pair(ladder.getBegin(), ladder.getEnd()));
	});
	auto snakes = board.getSnakes();
	std::for_each(snakes.begin(), snakes.end(), [&](Snake snake) {
		_stairs.insert(std::make_pair(snake.getBegin(), snake.getEnd()));
	});
}

GameState::~GameState()
{
}

void GameState::update(Player player, std::vector<int> moves) {

	if (_state == state::OVER)
		return;
	if (_state == state::NOT_STARTED)
		_state = state::IN_PROGRESS;

	std::for_each(moves.begin(), moves.end(), [&](int move) {
		auto pos = *_playerPositions.find(player.getId());
		auto new_pos = pos.second + move;

		if (new_pos <= _dimension * _dimension) {

			auto stair_itr = _stairs.find(new_pos);
			if (stair_itr != _stairs.end())
				new_pos = stair_itr->second;

			_playerPositions.insert_or_assign(player.getId(), new_pos);

			if (new_pos == _dimension * _dimension) {
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
