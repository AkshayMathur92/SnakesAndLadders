#pragma once
class Square
{
	int value;

public:
	Square(int value);
	~Square();
	Square operator ++();
	const int getValue()const;
};

