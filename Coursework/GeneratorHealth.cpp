#include "GeneratorHealth.hpp"
#include "GeneratorNumber.hpp"


Health GeneratorHealth::execute(const Range& rangeHealth) const
{
    const GeneratorNumber generator;
    const int value = generator.execute(rangeHealth);

    return Health(value);
}
