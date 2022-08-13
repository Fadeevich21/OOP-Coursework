#include "GeneratorDamage.hpp"
#include "GeneratorNumber.hpp"


Damage GeneratorDamage::generate(const Range& rangeDamage) const
{
    const GeneratorNumber generator;
    const int value = generator.generate(rangeDamage);

    return Damage(value);
}
