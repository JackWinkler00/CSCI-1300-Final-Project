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
    cout << name << " says: Welcome, traveler." << endl;
}