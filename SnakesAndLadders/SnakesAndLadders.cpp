// SnakesAndLadders.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SnakesAndLadder.h"
#include <chrono>
#include <iostream>
int main()
{
	auto init_time = std::chrono::high_resolution_clock().now();
	for (int i = 0; i < (1<<15); i++) 
		SnakesAndLadder().initGame();

	auto final_time = std::chrono::high_resolution_clock().now();
	auto time = (final_time - init_time).count() / std::pow(10.0, 9);
	auto GPS = ((1 << 15) / time);
	std::cout << GPS << std::endl;
	int i;
	std::cin >> i;

    return 0;
}

