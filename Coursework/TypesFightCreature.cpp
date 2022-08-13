#include "TypesFightCreature.hpp"
#include "GeneratorNumber.hpp"
#include <iostream>


int FightCreatureBot::getSlot() const
{
	const int min = 0;
	const int max = this->_commands.size() - 1;
	Range rangeSlots(min, max);

	GeneratorNumber generator;
	const int slot = generator.generate(rangeSlots);
	
	return slot;
}

std::string FightCreatureBot::handle() const
{
	return "Bot";
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

std::string FightCreaturePlayer::handle() const
{
	return "Player";
}

FightCreaturePlayer::FightCreaturePlayer(const Creature& creature)
	: FightCreature(creature)
{
}
