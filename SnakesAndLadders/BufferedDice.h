#pragma once
#include <queue>
#include <boost\circular_buffer.hpp>

class BufferedDice
{
	int _sided;
	std::queue<int, boost::circular_buffer<int>> _read_buff;
	std::queue<int, boost::circular_buffer<int>> _write_buff;
	void _fill(int);
	
public:
	BufferedDice(int);

	std::tuple<int,int,int> roll();
};

