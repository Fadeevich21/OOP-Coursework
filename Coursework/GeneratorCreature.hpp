#pragma once

#include "Creature.hpp"
#include "Range.hpp"


class GeneratorCreature
{
public:
	GeneratorCreature() = default;

	Creature generate(const Range& rangeHealth, const Range& rangeDamage) const;
};

