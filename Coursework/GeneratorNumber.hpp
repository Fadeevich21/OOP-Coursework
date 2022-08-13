#pragma once

#include "Range.hpp"


class GeneratorNumber
{
public:
	GeneratorNumber() = default;

	int generate(const Range& rangeValues) const;
};
