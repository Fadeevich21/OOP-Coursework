#include "CreatorFightCreature.hpp"
#include "GeneratorCreature.hpp"
#include "TypesFightCreature.hpp"


const Range CreatorFightCreature::_rangeHealthMaxValue = Range(900, 1000);
const Range CreatorFightCreature::_rangeDamage = Range(0, 70);


FightCreature* CreatorFightCreatureBot::execute()
{
    const GeneratorCreature generator;
    Creature creature = generator.execute(this->_rangeHealthMaxValue, this->_rangeDamage);
    creature.setName("Bot");
    FightCreature* const fightCreature = new FightCreatureBot(creature);

    return fightCreature;
}


FightCreature* CreatorFightCreaturePlayer::execute()
{
    const GeneratorCreature generator;
    Creature creature = generator.execute(this->_rangeHealthMaxValue, this->_rangeDamage);
    creature.setName("Player");
    FightCreature* const fightCreature = new FightCreaturePlayer(creature);

    return fightCreature;
}
