#pragma once
#include "Component.h"
#include <vector>
#include "Constants.h"
using namespace std;
class Entity :
	public Component
{
public:
	Entity(ComponentType type);
	virtual ~Entity();
	int getID();
	void addComponent(Component *component);
	void removeComponent(Component *component);
	vector<Component *> *getAllComponentsOfType(ComponentType type);
	bool isEntity();
	virtual bool isType(ComponentType type);
private:
	static int nextID;
	int id;
	ComponentType typeOfEntity;
	vector<Component *> components;
};

