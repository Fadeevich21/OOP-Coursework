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

private:
	void prepareHealth();

public:
	Creature(const Health& health, const Range& rangeDamage);

	Health getHealth() const;
	Range getRangeHealth() const;
	Range getRangeDamage() const;

	void changeNumberOfHealth(const int value);

	std::string getInfo() const;
};

