#include "CreatureDamageInfo.hpp"


CreatureDamageInfo::CreatureDamageInfo(const Range& range)
	: _range(range)
{
}

Range CreatureDamageInfo::getRange() const
{
	return this->_range;
}
