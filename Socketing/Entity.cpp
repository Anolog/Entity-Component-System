#include "stdafx.h"
#include "Entity.h"

int Entity::nextID = 0;

Entity::Entity(ComponentType type)
{
	typeOfEntity = type;
	id = nextID++;
}


Entity::~Entity()
{
}

int Entity::getID()
{
	return id;
}

void Entity::addComponent(Component *component)
{
	components.push_back(component);
}

void Entity::removeComponent(Component *component)
{
	for (int i = 0; i < (int)(components.size()); i++)
	{
		Component *c = components[i];
		if (c == component)
		{
			components.erase(components.begin() + i);
			return;
		}
		if (c->isEntity())
		{
			((Entity *)c)->removeComponent(component);
		}
	}
}

vector<Component *> *Entity::getAllComponentsOfType(ComponentType type)
{
	vector<Component *> *result = new vector<Component *>();
	for (int i = 0; i < (int)(components.size()); i++)
	{
		Component *c = components[i];
		if (c->isType(type))
		{
			result->push_back(c);
		}
		if (c->isEntity())
		{
			vector<Component *> *resultFromEntity = ((Entity *)c)->getAllComponentsOfType(type);
			for (int j = 0; j < (int)(resultFromEntity->size()); j++)
			{
				result->push_back(resultFromEntity->at(j));
			}
			delete resultFromEntity;
		}
	}
	return result;
}

bool Entity::isEntity()
{
	return true;
}

bool Entity::isType(ComponentType type)
{
	return typeOfEntity == type;
}