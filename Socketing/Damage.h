#pragma once
#include "Component.h"
class Damage :
	public Component
{
public:
	Damage(int min, int max);
	virtual ~Damage();
	virtual bool isType(ComponentType type);
	int calculateDamage();
private:
	int minimum;
	int maximum;
};

