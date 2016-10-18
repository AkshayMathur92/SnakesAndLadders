#include "stdafx.h"
#include "Game.h"
#include <iostream>

Game::Game(Board &board , DiceFactory &dice, std::vector<Player> &players):_diceFactory(dice),_players(players),_gameState(board,players)
{

}

Game::~Game()
{
}

void Game::run()
{
	while (_gameState.getState() != state::OVER) {
		for each(Player player in _players) {
			auto newDice = _diceFactory.newDice();
			player.rollDice(newDice);
			auto dice = player.getDice();
			if (dice.getId() != newDice.getId()) {
				// Player tried to cheat skipping turn
				continue;
			}
			//TODO skipping move verfication with returned dice
			_gameState.update(player, player.getMoves());
			if (_gameState.getState() == state::OVER)
				break;
		}
	}
	//OUTPUT WINNER 
	//std::cout << "Winner is Player " << _gameState.getWinner().getId()<<std::endl;
}
