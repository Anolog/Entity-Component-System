#pragma once
#include "Entity.h"
class SideEffect :
    public Component
{
public:
    SideEffect(int min, int max, int duration, std::string type);
    virtual ~SideEffect();
    virtual bool isType(ComponentType type);
    int calculateEffect();
    std::string getRuneType();
    int getRounds();


private:
    int minimum;
    int maximum;
    int rounds;
    std::string typeOfRune;
};

