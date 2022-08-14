#pragma once

#include "Health.hpp"
#include "Range.hpp"


class GeneratorHealth
{
public:
	GeneratorHealth() = default;

	Health execute(const Range& rangeHealth) const;
};

