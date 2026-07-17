#include "Character.h"
#include <iostream>

using namespace std;


Character::Character()
{
    name = "Unknown";
    health = 100;
    location = "Unknown";
    friendship = 0;
}


Character::Character(string n, int h, string l)
{
    name = n;
    health = h;
    location = l;
    friendship = 0;
}


void Character::setName(string n)
{
    name = n;
}


string Character::getName()
{
    return name;
}


void Character::setLocation(string l)
{
    location = l;
}


string Character::getLocation()
{
    return location;
}

void Character::setHealth(int h)
{
    health = h;
}


int Character::getHealth()
{
    return health;
}

int Character::getFriendship()
{
    return friendship;
}


void Character::increaseFriendship(int amount)
{
    friendship += amount;
}


void Character::talk()
{
    cout << name << " says: ";
    
    if(name == "Gandalf")
    {
        cout << "The road ahead is dangerous, but courage will guide you." << endl;
    }

    else if(name == "Aragorn")
    {
        cout << "Stay strong. The Fellowship depends on you." << endl;
        cout << "Gandalf seems to be holding something of great value..." << endl;
    }

    else if(name == "Legolas")
    {
        cout << "The forests of Middle Earth still hold many secrets." << endl;
        cout << "I head that wretched creature Gollum may still have the ring..." << endl;
    }

    else if(name == "Gimli")
    {
        cout << "A true warrior never abandons the quest! Or breakfast..." << endl;
    }

    else
    {
        cout << "I have nothing to say." << endl;
    }
}