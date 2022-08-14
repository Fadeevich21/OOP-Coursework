#include "Creature.hpp"
#include "GeneratorDamage.hpp"


Creature::Creature(const CreatureHealthInfo& healthInfo, const CreatureDamageInfo& damageInfo)
	: _healthInfo(healthInfo), _damageInfo(damageInfo)
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


void Creature::changeNumberOfHealth(const int value)
{
	this->_healthInfo.changeValue(value);
}


Damage Creature::getDamage() const
{
	const GeneratorDamage generator;
	const Range rangeDamage = this->_damageInfo.getRange();
	const Damage damage = generator.execute(rangeDamage);

	return damage;
}

int Creature::getHealthValue() const
{
	return this->_healthInfo.getValue();
}

Range Creature::getHealthRange() const
{
	return this->_healthInfo.getRange();
}


std::string Creature::getInfo() const
{
	std::string info;
	info += "Name: " + getName() + '\n';
	info += "Health: " + std::to_string(this->_healthInfo.getValue()) + " hp";

	return info;
}
