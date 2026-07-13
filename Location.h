#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include "Item.h"
#include "Character.h"

using namespace std;

class Location
{
private:
    string name;
    string description;
    bool unlocked;

    vector<Item> items;
    vector<Character> characters;

public:
    Location();

    Location(string n, string d, bool u);

    string getName();
    string getDescription();

    bool isUnlocked();
    void unlock();

    void addItem(Item item);
    void addCharacter(Character character);

    void displayLocation();

    Item searchForItem();

    vector<Character> getCharacters();
};

#endif