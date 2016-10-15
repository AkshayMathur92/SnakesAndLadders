#pragma once
class Stair
{
protected:
	int _begin;
	int _end;
public:
	virtual ~Stair() {};
	virtual const int getBegin() const = 0;
	virtual const int getEnd() const = 0;
};

