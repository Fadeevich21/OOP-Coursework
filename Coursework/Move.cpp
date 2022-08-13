#include "Move.hpp"


Move::Move(FightCreature* const fightCreature)
	: _fightCreature(fightCreature)
{
}

void Move::setFightCreature(FightCreature* const fightCreature)
{
	this->_fightCreature = fightCreature;
}

FightCreature* Move::getFightCreature() const
{
	return this->_fightCreature;
}

void Move::execute()
{
	this->_fightCreature->action();
}
