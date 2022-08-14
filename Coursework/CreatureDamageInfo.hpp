#pragma once

#include "Range.hpp"


class CreatureDamageInfo
{
private:
	Range _range;

public:
	CreatureDamageInfo(const Range& range);

	Range getRange() const;
};
