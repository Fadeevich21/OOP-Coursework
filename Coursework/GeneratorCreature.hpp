#pragma once

#include "Creature.hpp"
#include "Range.hpp"


class GeneratorCreature
{
public:
	GeneratorCreature() = default;

	Creature execute(const Range& rangeHealthMaxValue, const Range& rangeDamage) const;
};

