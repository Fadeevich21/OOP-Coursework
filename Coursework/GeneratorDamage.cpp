#include "GeneratorDamage.hpp"
#include "GeneratorNumber.hpp"


Damage GeneratorDamage::execute(const Range& rangeDamage) const
{
    const GeneratorNumber generator;
    const int value = generator.execute(rangeDamage);

    return Damage(value);
}
