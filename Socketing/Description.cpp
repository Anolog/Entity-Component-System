#include "stdafx.h"
#include "Description.h"


Description::Description(string desc)
{
	description = desc;
}


Description::~Description()
{
}

bool Description::isType(ComponentType type)
{
	return type == ComponentType::DESCRIPTION;
}

string Description::getDescription()
{
	return description;
}