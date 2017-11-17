#pragma once
#include "Constants.h"

class Component
{
public:
	Component();
	virtual ~Component();
	virtual bool isEntity();
	virtual bool isType(ComponentType type) = 0;
private:
};

