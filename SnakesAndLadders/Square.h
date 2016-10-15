#pragma once
class Square
{
	int _value;

public:
	Square(int value);
	~Square();
	Square operator ++();
	const int getValue()const;
};

