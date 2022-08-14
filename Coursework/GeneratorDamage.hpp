#pragma once

#include "Damage.hpp"
#include "Range.hpp"


class GeneratorDamage
{
public:
	GeneratorDamage() = default;

	Damage execute(const Range& rangeDamage) const;
};

