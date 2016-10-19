#pragma once
class Stair
{
protected:
	int _begin;
	int _end;
public:
	Stair(int begin, int end) :_begin(begin), _end(end) {}
	const int getBegin() const {
		return _begin;
	}
	const int getEnd() const {
		return _end;
	}
};

