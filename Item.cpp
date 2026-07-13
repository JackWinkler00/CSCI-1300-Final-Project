#include "Item.h"
#include <iostream>

using namespace std;

Item::Item()
{
    name = "Unknown";
    type = "Unknown";
    value = 0;
    questItem = false;
}

Item::Item(string n, string t, int v, bool q)
{
    name = n;
    type = t;
    value = v;
    questItem = q;
}

string Item::getName()
{
    return name;
}

string Item::getType()
{
    return type;
}

int Item::getValue()
{
    return value;
}

bool Item::isQuestItem()
{
    return questItem;
}

void Item::display()
{
    cout << name << " (" << type << ")";

    if (questItem)
    {
        cout << " [Quest Item]";
    }

    cout << " - Value: " << value << " gold" << endl;
}