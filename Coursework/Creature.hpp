#pragma once

#include "Health.hpp"
#include "Range.hpp"
#include <string>


class Creature
{
private:
	Health _health;
	Range _rangeHealth;
	Range _rangeDamage;
	std::string _name;

private:
	void prepareHealth();

public:
	Creature(const Health& health, const Range& rangeDamage);

	void setName(const std::string& name);
	std::string getName() const;

	Health getHealth() const;
	Range getRangeHealth() const;
	Range getRangeDamage() const;

	void changeNumberOfHealth(const int value);

	std::string getInfo() const;
};

