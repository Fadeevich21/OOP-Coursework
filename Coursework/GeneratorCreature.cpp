#include "GeneratorCreature.hpp"
#include "GeneratorHealth.hpp"
#include "CreatureHealthInfo.hpp"
#include "CreatureDamageInfo.hpp"


Creature GeneratorCreature::execute(const Range& rangeHealthMaxValue, const Range& rangeDamage) const
{
    const GeneratorHealth generator;
    const Health health = generator.execute(rangeHealthMaxValue);
    const Range rangeHealth = Range(0, health.getValue());

    const CreatureHealthInfo healthInfo(health, rangeHealth);
    const CreatureDamageInfo damageInfo(rangeDamage);

    return Creature(healthInfo, damageInfo);
}
