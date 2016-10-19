#include "stdafx.h"
#include "SnakesAndLadder.h"
#include "DiceFactory.h"
#include "BoardBuilder.h"
#include "Player.h"
#include "Game.h"
#include "BufferedDice.h"

void SnakesAndLadder::initGame()
{
	BoardBuilder builder(10);
	builder.addStair(2, 92);
	builder.addStair(98, 8);
	builder.addStair(10, 21);
	builder.addStair(45, 28);
	auto board = builder.build();

	//DiceFactory dice(3, 6);
	BufferedDice dice(6);

	Player p1(1);
	Player p2(2);
	Player p3(3);

	std::vector<Player> players = { p1,p2,p3 };

	Game game(board, dice, players);
	game.run();
}
