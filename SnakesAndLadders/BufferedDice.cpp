#include "stdafx.h"
#include "BufferedDice.h"
#include <stdexcept>
#include <future>
#include <stdlib.h>
#include <iostream>

BufferedDice::BufferedDice(int sided):_read_buff(boost::circular_buffer<int>(256)),_write_buff(boost::circular_buffer<int>(256))
{
	if (sided > 3)
		_sided = sided;
	else
		throw std::invalid_argument("Sides should be > 4");
	
	int upto = 256;
	while (upto-- > 0) {
		_read_buff.push(rand()%6 + 1);
	}
}

void BufferedDice::_fill(int upto)
{
	std::cout << "Fill Launched" << std::endl;
	while (upto-- > 0) {
		_write_buff.push(rand() % 6 + 1);
	}
}

std::tuple<int,int,int> BufferedDice::roll()
{
	auto move1 = _read_buff.front();
	int move2 = 0;
	int move3 = 0;
	_read_buff.pop();
	if (move1 == 6) {
		move2 = _read_buff.front();
		_read_buff.pop();
	}
	if (move2 == 6) {
		move3 = _read_buff.front();
		_read_buff.pop();
	}
	auto a = [](int a) {};
	if (_read_buff.size() < 6) {
		std::swap(_read_buff, _write_buff);
		std::async(std::launch::async, [&](int val) {_fill(val); }, 250);
		std::cout << "Launched" << std::endl;
	}
	if (move1 == 6 && move2 == 6 && move3 == 6)
		return std::tuple<int,int,int>({ 0,0,0 });
	else
		return std::tuple<int,int,int>({ move1, move2, move3 });
}
