#pragma once

#include "Damage.hpp"
#include "Range.hpp"


class GeneratorDamage
{
public:
	GeneratorDamage() = default;

	Damage generate(const Range& rangeDamage) const;
};

