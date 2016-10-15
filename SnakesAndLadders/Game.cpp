#include "stdafx.h"
#include "Game.h"

Game::Game(Board board , Dice dice, std::vector<Player> players):_dice(dice),_players(players),_gameState(board,players)
{

}

Game::~Game()
{
}
