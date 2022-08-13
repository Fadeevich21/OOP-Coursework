#include "Creature.hpp"

Creature::Creature(const Health& health, const Range& rangeDamage)
	: _health(health), _rangeDamage(rangeDamage), _rangeHealth(0, health.getValue())
{
}

void Creature::setName(const std::string& name)
{
	this->_name = name;
}

std::string Creature::getName() const
{
	return this->_name;
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


bool isHealthLessMin(const Range& rangeHealth, const Health& health)
{
	return health.getValue() < rangeHealth.min;
}

bool isHealthGreatMax(const Range& rangeHealth, const Health& health)
{
	return health.getValue() > rangeHealth.max;
}

void Creature::prepareHealth()
{
	if (isHealthLessMin(this->_rangeHealth, this->_health))
	{
		this->_health.setValue(this->_rangeHealth.min);
	}

	if (isHealthGreatMax(this->_rangeHealth, this->_health))
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
	info += "Name: " + getName() + '\n';
	info += "Health: " + std::to_string(this->_health.getValue()) + " hp";

	return info;
}
