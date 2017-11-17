#pragma once
#include "Component.h"
#include <string>
using namespace std;
class Description :
	public Component
{
public:
	Description(string desc);
	virtual ~Description();
	virtual bool isType(ComponentType type);
	string getDescription();
private:
	string description;
};

