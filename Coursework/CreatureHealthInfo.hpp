#pragma once

#include "Health.hpp"
#include "Range.hpp"


class CreatureHealthInfo
{
private:
	Health _health;
	Range _range;

public:
	CreatureHealthInfo(const Health& health, const Range& range);
	
	int getValue() const;
	void setValue(const int value);
	void changeValue(const int value);

	Range getRange() const;
};
