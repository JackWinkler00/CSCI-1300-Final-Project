#include "Location.h"
#include <iostream>

using namespace std;


Location::Location()
{
    name = "Unknown";
    description = "Unknown location";
    unlocked = false;
}


Location::Location(string n, string d, bool u)
{
    name = n;
    description = d;
    unlocked = u;
}


string Location::getName()
{
    return name;
}


string Location::getDescription()
{
    return description;
}


bool Location::isUnlocked()
{
    return unlocked;
}


void Location::unlock()
{
    unlocked = true;
}


void Location::addItem(Item item)
{
    items.push_back(item);
}


void Location::addCharacter(Character character)
{
    characters.push_back(character);
}


void Location::displayLocation()
{
    cout << "\n========== " << name << " ==========" << endl;
    cout << description << endl;

    cout << "\nCharacters here:" << endl;

    if (characters.size() == 0)
    {
        cout << "None" << endl;
    }
    else
    {
        for (int i = 0; i < characters.size(); i++)
        {
            cout << "- " << characters[i].getName() << endl;
        }
    }

    cout << "\nItems available:" << endl;

    if (items.size() == 0)
    {
        cout << "None" << endl;
    }
    else
    {
        for (int i = 0; i < items.size(); i++)
        {
            cout << "- " << items[i].getName() << endl;
        }
    }
}


Item Location::searchForItem()
{
    if (items.size() > 0)
    {
        Item found = items.back();
        //Removes the last elemnt from the vector
        items.pop_back();

        return found;
    }

    return Item();
}


vector<Character> Location::getCharacters()
{
    return characters;
}