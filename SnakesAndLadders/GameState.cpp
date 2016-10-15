#include "stdafx.h"
#include "GameState.h"
#include <algorithm>
#include <utility>


GameState::GameState(Board board, std::vector<Player> players):_board(board)
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

		if (new_pos < _board.getDimesion() * _board.getDimesion()) {

			std::find_if(_board.getLadders().begin(), _board.getLadders().end(), [&](Ladder ladder) {
				if (ladder.getBegin() == new_pos) {
					new_pos = ladder.getEnd();
					return true;
				}
				return false;
			});

			std::find_if(_board.getSnakes().begin(), _board.getSnakes().end(), [&](Snake snake) {
				if (snake.getBegin() == new_pos) {
					new_pos = snake.getEnd();
					return true;
				}
				return false;
			});

			_playerPositions.insert_or_assign(player.getId(), new_pos);

			if (new_pos == _board.getDimesion() * _board.getDimesion()) {
				_winner = player;
				_state = state::OVER;
			}
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
	if (_state != state::OVER) {
		return _winner.get();
	}
	else
		throw std::exception("Game if not over. cannot decide winner.");
}
