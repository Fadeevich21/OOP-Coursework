#include "TypesFightCreature.hpp"
#include "GeneratorNumber.hpp"
#include <iostream>


int FightCreatureBot::getSlot() const
{
	const int min = 0;
	const int max = this->_commands.size() - 1;
	const Range rangeSlots(min, max);

	const GeneratorNumber generator;
	const int slot = generator.generate(rangeSlots);
	
	return slot;
}

FightCreatureBot::FightCreatureBot(const Creature& creature)
	: FightCreature(creature)
{
}


int FightCreaturePlayer::getSlot() const
{
	size_t slot;
	do
	{
		std::cout << "Select command:\n";
		printCommands();
		std::cin >> slot;
		std::cout << '\n';
	}
	while (slot >= this->_commands.size());

	return slot;
}

FightCreaturePlayer::FightCreaturePlayer(const Creature& creature)
	: FightCreature(creature)
{
}
