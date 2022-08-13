#pragma once

#include "Health.hpp"
#include "Range.hpp"


class GeneratorHealth
{
public:
	GeneratorHealth() = default;

	Health generate(const Range& rangeHealth) const;
};

