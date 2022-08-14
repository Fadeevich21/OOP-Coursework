#pragma once

#include "Range.hpp"


class GeneratorNumber
{
public:
	GeneratorNumber() = default;

	int execute(const Range& rangeValues) const;
	int execute(const int min, const int max) const;
};
