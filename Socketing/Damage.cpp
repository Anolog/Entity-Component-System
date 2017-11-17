#include "stdafx.h"
#include "Damage.h"
#include <stdlib.h> 

Damage::Damage(int min, int max)
{
	minimum = min;
	maximum = max;
}


Damage::~Damage()
{
}

bool Damage::isType(ComponentType type)
{
	return type == ComponentType::DAMAGE;
}

int Damage::calculateDamage()
{
	if (minimum == maximum)
	{
		return minimum;
	}
	int range = maximum - minimum + 1;
	int result = rand() % range + minimum;
	return result;
}