#include "GeneratorNumber.hpp"
#include <random>


int GeneratorNumber::generate(const Range& rangeValues) const
{
    const int value = rand() % (rangeValues.max - rangeValues.min + 1) + rangeValues.min;

    return value;
}
