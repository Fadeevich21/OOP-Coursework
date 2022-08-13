#include "GeneratorHealth.hpp"
#include "GeneratorNumber.hpp"


Health GeneratorHealth::generate(const Range& rangeHealth) const
{
    GeneratorNumber generator;
    const int value = generator.generate(rangeHealth);

    return Health(value);
}
