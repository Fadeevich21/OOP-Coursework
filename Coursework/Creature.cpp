#include "Creature.hpp"

Creature::Creature(const Health& health, const Range& rangeDamage)
	: _health(health), _rangeDamage(rangeDamage), _rangeHealth(0, health.getValue())
{
}

Health Creature::getHealth() const
{
	return this->_health;
}

Range Creature::getRangeHealth() const
{
	return this->_rangeHealth;
}

Range Creature::getRangeDamage() const
{
	return this->_rangeDamage;
}


void Creature::prepareHealth()
{
	if (this->_health.getValue() < this->_rangeHealth.min)
	{
		this->_health.setValue(this->_rangeHealth.min);
	}

	if (this->_health.getValue() > this->_rangeHealth.max)
	{
		this->_health.setValue(this->_rangeHealth.max);
	}
}

void Creature::changeNumberOfHealth(const int value)
{
	this->_health.change(value);
	prepareHealth();
}

std::string Creature::getInfo() const
{
	std::string info;
	info += "Health: " + std::to_string(this->_health.getValue()) + "hp";

	return info;
}
