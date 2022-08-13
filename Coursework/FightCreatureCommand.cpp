#include "FightCreatureCommand.hpp"

FightCreatureCommandHit::FightCreatureCommandHit(FightCreature* lhs, FightCreature* rhs)
	: _fightCreature1(lhs), _fightCreature2(rhs)
{
}

std::string FightCreatureCommandHit::handle() const
{
	return "Hit";
}

void FightCreatureCommandHit::execute()
{
	const Damage damage = this->_fightCreature1->getDamage();
	this->_fightCreature2->haveDamage(damage);
}

FightCreatureCommandSurrender::FightCreatureCommandSurrender(FightCreature* fightCreature)
	: _fightCreature(fightCreature)
{
}

std::string FightCreatureCommandSurrender::handle() const
{
	return "Surrender";
}

void FightCreatureCommandSurrender::execute()
{
	this->_fightCreature->setState(FightCreature::FightCreatureState::LOSE);
}
