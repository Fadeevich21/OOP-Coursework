#include "GeneratorCreature.hpp"
#include "GeneratorHealth.hpp"


Creature GeneratorCreature::generate(const Range& rangeHealth, const Range& rangeDamage) const
{
    const GeneratorHealth generator;
    const Health health = generator.generate(rangeHealth);

    return Creature(health, rangeDamage);
}
