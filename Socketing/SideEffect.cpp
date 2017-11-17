#include "stdafx.h"
#include "SideEffect.h"


SideEffect::SideEffect(int min, int max, int duration, std::string type)
{
    minimum = min;
    maximum = max;
    rounds = duration;
    typeOfRune = type;
}


SideEffect::~SideEffect()
{
}

bool SideEffect::isType(ComponentType type)
{
    return type == ComponentType::SIDE_EFFECT;
}

int SideEffect::calculateEffect()
{
    int sideEffectDamage = 0;

    for (int i = 0; i < rounds; i++)
    {
        int range = minimum - maximum + 1;

        sideEffectDamage = (rand() % range + minimum);
    }

    return sideEffectDamage;
}

int SideEffect::getRounds()
{
    return rounds;
}

string SideEffect::getRuneType()
{
    return typeOfRune;
}