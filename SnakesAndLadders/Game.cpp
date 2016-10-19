#include "stdafx.h"
#include "Game.h"
#include <iostream>

Game::Game(Board &board , BufferedDice &dice, const std::vector<Player> &players):_dice(dice),_players(players),_gameState(board,players)
{

}

void Game::run()
{
	while (_gameState.getState() != state::OVER) {
		for (const Player& player : _players) {
			
			_gameState.update(player, player.getMoves(_dice.roll()));
			if (_gameState.getState() == state::OVER)
				break;
		}
	}
	//OUTPUT WINNER 
	//std::cout << "Winner is Player " << _gameState.getWinner().getId()<<std::endl;
}
