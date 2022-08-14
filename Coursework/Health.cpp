#include "Health.hpp"


Health::Health(const int value)
	: _value(value)
{
}


void Health::setValue(const int value)
{
	this->_value = value;
}

int Health::getValue() const
{
	return this->_value;
}
