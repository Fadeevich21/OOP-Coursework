#include "TypesFightCreature.hpp"
#include "GeneratorNumber.hpp"
#include <iostream>
#include <algorithm>


int FightCreatureBot::getSlot() const
{
	const int min = 0;
	const int max = std::max(int(this->_commands.size()) - 1, 0);

	const GeneratorNumber generator;
	const int slot = generator.execute(min, max);
	
	return slot;
}

FightCreatureBot::FightCreatureBot(const Creature& creature)
	: FightCreature(creature)
{
}


int FightCreaturePlayer::getSlot() const
{
	int slot;
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
