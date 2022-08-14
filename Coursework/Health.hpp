#pragma once

class Health
{
private:
	int _value;

public:
	Health(const int value);
	
	void setValue(const int value);
	int getValue() const;
};
