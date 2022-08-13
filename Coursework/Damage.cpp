#include "Damage.hpp"

Damage::Damage(const int value)
	: _value(value)
{
}

int Damage::getValue() const
{
	return this->_value;
}
