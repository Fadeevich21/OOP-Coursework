#include "GeneratorNumber.hpp"
#include <random>


int GeneratorNumber::execute(const Range& rangeValues) const
{
    const int value = rand() % (rangeValues.max - rangeValues.min + 1) + rangeValues.min;

    return value;
}

int GeneratorNumber::execute(const int min, const int max) const
{
    return execute(Range(min, max));
}
