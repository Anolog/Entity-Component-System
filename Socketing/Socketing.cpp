// Socketing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Entity.h"
#include "Component.h"
#include "Damage.h"
#include "Description.h"
#include "SideEffect.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

Entity *weapon = NULL;
void addGem();
void addRune();
void addSocket();
void createWeapon();
void displayWeapon();
void attack();


int _tmain(int argc, _TCHAR* argv[])
{

    srand((unsigned int)time(NULL));

	while (true)
	{
		int choice = 0;
		cout << "1 - create new weapon" << endl;
		cout << "2 - add socket to existing weapon" << endl;
		cout << "3 - add gem to empty socket" << endl;
		cout << "4 - add rune to empty weapon" << endl;
		cout << "5 - attack" << endl;
		cout << "6 - quit application" << endl;
		cout << ">";
		cin >> choice;
		switch (choice)
		{
		case 6:
			return 0;
		case 5:
			attack();
			break;
		case 4: addRune();
			break;
		case 3:
			addGem();
			break;
		case 2:
			addSocket();
			break;
		case 1:
			createWeapon();
			break;
		}
		displayWeapon();
	}
	return 0;
}

void addGem()
{
	// are there any empty sockets?
	// and do we even have a weapon?
	if (weapon == NULL)
	{
		cout << "Need to create a weapon first." << endl;
		return;
	}
	vector<Component *> *sockets = weapon->getAllComponentsOfType(ComponentType::SOCKET);
	if (sockets->size() == 0)
	{
		cout << "need to create some sockets first." << endl;
		return;
	}

	//do we have any empty sockets?
	for (int i = 0; i < sockets->size(); i++)
	{
		Entity *socket = (Entity *)(sockets->at(i));
		vector<Component *> *emptySockets = socket->getAllComponentsOfType(ComponentType::EMPTY);
		if (emptySockets->size() != 0)
		{
			// this socket has an empty slot
			// remove it.
			socket->removeComponent(emptySockets->at(0));
			// and replace with a gem.
			int coin = rand() % 4;
			if (coin == 0)
			{
				// Amber - does +3 damage
				Entity *gem = new Entity(ComponentType::GEM);
				gem->addComponent(new Description("+3 Amber Gem"));
				gem->addComponent(new Damage(3, 3));
				weapon->addComponent(gem);
			}
			else if (coin == 1)
			{
				// Sapphire - does 2-10 damage
				Entity *gem = new Entity(ComponentType::GEM);
				gem->addComponent(new Description("2-10 Sapphire gem"));
				gem->addComponent(new Damage(2, 10));
				weapon->addComponent(gem);
			}
			else if (coin == 2)
			{
				// Diamond - does +20 damage
				Entity *gem = new Entity(ComponentType::GEM);
				gem->addComponent(new Description("+20 Diamond gem"));
				gem->addComponent(new Damage(20, 20));
				weapon->addComponent(gem);
			}

            else if (coin == 3)
            {
                Entity *gem = new Entity(ComponentType::GEM);
                gem->addComponent(new Description("+10 Bacon"));
                gem->addComponent(new Damage(10, 10));
                weapon->addComponent(gem);
            }
			// then return.
			return; // we have added a gem
		}
		
	}
	cout << "All sockets are full" << endl;
}

void addSocket()
{
	Entity *socket = new Entity(ComponentType::SOCKET);
	Entity *emptySocket = new Entity(ComponentType::EMPTY);
	emptySocket->addComponent(new Description("Empty Socket"));
	socket->addComponent(emptySocket);
	weapon->addComponent(socket);
}

void createWeapon()
{
	if (weapon != NULL)
	{
		delete weapon;
	}
	weapon = new Entity(ComponentType::WEAPON);

	// can either be a sword, or a dagger
	int coin = rand() % 4;
	if (coin == 0)
	{
		// sword
		Entity *weapontype = new Entity(ComponentType::WEAPONTYPE);
		weapontype->addComponent(new Description("Sword"));
		weapontype->addComponent(new Damage(4, 10));
		weapon->addComponent(weapontype);
	}
    else if (coin == 1)
	{
		// dagger
		Entity *weapontype = new Entity(ComponentType::WEAPONTYPE);
		weapontype->addComponent(new Description("Dagger"));
		weapontype->addComponent(new Damage(2, 6));
		weapon->addComponent(weapontype);
	}

    else if (coin == 2)
    {
        // Griffyn
        Entity *weapontype = new Entity(ComponentType::WEAPONTYPE);
        weapontype->addComponent(new Description("Axe"));
        weapontype->addComponent(new Damage(0, 1));
        weapon->addComponent(weapontype);
    }

    else if (coin == 3)
    {
        // dagger
        Entity *weapontype = new Entity(ComponentType::WEAPONTYPE);
        weapontype->addComponent(new Description("Staff"));
        weapontype->addComponent(new Damage(2, 5));
        weapon->addComponent(weapontype);
    }
}

void addRune()
{
    // are there any empty sockets?
    // and do we even have a weapon?
    if (weapon == NULL)
    {
        cout << "Need to create a weapon first." << endl;
        return;
    }
    vector<Component *> *sockets = weapon->getAllComponentsOfType(ComponentType::SOCKET);
    if (sockets->size() == 0)
    {
        cout << "need to create some sockets first." << endl;
        return;
    }

    //do we have any empty sockets?
    for (int i = 0; i < sockets->size(); i++)
    {
        Entity *socket = (Entity *)(sockets->at(i));
        vector<Component *> *emptySockets = socket->getAllComponentsOfType(ComponentType::EMPTY);
        if (emptySockets->size() != 0)
        {
            // this socket has an empty slot
            // remove it.
            socket->removeComponent(emptySockets->at(0));
            // and replace with a rune.
            int coin = rand() % 5;
            if (coin == 0)
            {
                // Fire
                Entity *rune = new Entity(ComponentType::RUNE);
                rune->addComponent(new Description("Rune of Fire"));
                rune->addComponent(new SideEffect(3, 5, 2, "Fire"));
                weapon->addComponent(rune);
            }
            else if (coin == 1)
            {
                // Plague
                Entity *rune = new Entity(ComponentType::RUNE);
                rune->addComponent(new Description("Rune of Plague"));
                rune->addComponent(new SideEffect(2, 10, 4, "Plague"));
                weapon->addComponent(rune);
            }
            else if (coin == 2)
            {
                // Frost
                Entity *rune = new Entity(ComponentType::RUNE);
                rune->addComponent(new Description("Rune of Frost"));
                rune->addComponent(new SideEffect(8, 14, 1, "Frost"));
                weapon->addComponent(rune);
            }

            else if (coin == 3)
            {
                Entity *rune = new Entity(ComponentType::RUNE);
                rune->addComponent(new Description("Rune of OverPowered"));
                rune->addComponent(new SideEffect(40, 80, 1, "OverPowered"));
                weapon->addComponent(rune);
            }

            else if (coin == 4)
            {
                Entity *rune = new Entity(ComponentType::RUNE);
                rune->addComponent(new Description("Rune of Arcane"));
                rune->addComponent(new SideEffect(5, 10, 1, "Arcane"));
                weapon->addComponent(rune);
            }
            // then return.
            return; // we have added a rune
        }

    }
    cout << "All sockets are full" << endl;

}

void displayWeapon()
{
	if (weapon == NULL)
	{
		return;
	}
	vector<Component *> *descriptions = weapon->getAllComponentsOfType(ComponentType::DESCRIPTION);
	for (int i = 0; i < descriptions->size(); i++)
	{
		Description *desc = (Description *)(descriptions->at(i)); // convert from Component * to Description *
		cout << desc->getDescription() << endl;
	}
}

void attack()
{
	if (weapon == NULL)
	{
		return;
	}
	int damage = 0;
	vector<Component *> *damages = weapon->getAllComponentsOfType(ComponentType::DAMAGE);
    vector<Component *> *runes = weapon->getAllComponentsOfType(ComponentType::SIDE_EFFECT);

	for (int i = 0; i < damages->size(); i++)
	{
		Damage *dam = (Damage *)(damages->at(i)); // convert from Component * to Damage *
		damage += dam->calculateDamage();
	}
	cout << "You do " << damage << " points of damage." << endl;

    for (int i = 0; i < runes->size(); i++)
    {
        SideEffect *sideff = (SideEffect *)(runes->at(i));
        for (int j = 0; j < sideff->getRounds(); j++)
        {
            cout << sideff->calculateEffect() << " points of " << sideff->getRuneType()  << endl;
        } 
    }
}