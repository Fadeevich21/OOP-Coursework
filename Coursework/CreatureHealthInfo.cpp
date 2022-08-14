#include "CreatureHealthInfo.hpp"
#include <algorithm>

CreatureHealthInfo::CreatureHealthInfo(const Health& health, const Range& range)
	: _health(health), _range(range)
{
}

int CreatureHealthInfo::getValue() const
{
	return this->_health.getValue();
}

void CreatureHealthInfo::setValue(const int value)
{
	this->_health.setValue(value);
}


void process(const Range& hpRange, int& hp)
{
	hp = std::max(hp, hpRange.min);
	hp = std::min(hp, hpRange.max);
}

void CreatureHealthInfo::changeValue(const int value)
{
	int hp = getValue() + value;
	process(getRange(), hp);
	setValue(hp);
}

Range CreatureHealthInfo::getRange() const
{
	return this->_range;
}
