#pragma once
#include <stdexcept>
class Ladder
{
protected:
	int begin;
	int end;
public:
	Ladder(int, int);
	~Ladder();
	const int getBegin() const;
	const int getEnd() const;
};

