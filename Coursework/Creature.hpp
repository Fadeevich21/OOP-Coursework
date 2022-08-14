#pragma once

#include "CreatureHealthInfo.hpp"
#include "CreatureDamageInfo.hpp"
#include "Damage.hpp"
#include <string>


class Creature
{
private:
	std::string _name;
	CreatureHealthInfo _healthInfo;
	CreatureDamageInfo _damageInfo;

public:
	Creature(const CreatureHealthInfo& healthInfo, const CreatureDamageInfo& damageInfo);

	void setName(const std::string& name);
	std::string getName() const;

	void changeNumberOfHealth(const int value);

	Damage getDamage() const;
	int getHealthValue() const;
	Range getHealthRange() const;

	std::string getInfo() const;
};

