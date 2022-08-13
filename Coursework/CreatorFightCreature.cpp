#include "CreatorFightCreature.hpp"
#include "GeneratorCreature.hpp"
#include "TypesFightCreature.hpp"


FightCreature* CreatorFightCreatureBot::execute()
{
    static Range rangeHealth(900, 1000);
    static Range rangeDamage(0, 70);
    GeneratorCreature generator;
    Creature creature = generator.generate(rangeHealth, rangeDamage);
    FightCreature* fightCreature = new FightCreatureBot(creature);

    return fightCreature;
}


FightCreature* CreatorFightCreaturePlayer::execute()
{
    static Range rangeHealth(900, 1000);
    static Range rangeDamage(0, 70);
    GeneratorCreature generator;
    Creature creature = generator.generate(rangeHealth, rangeDamage);
    FightCreature* fightCreature = new FightCreaturePlayer(creature);

    return fightCreature;
}
