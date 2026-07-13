#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
private:
    string name;
    string type;
    int value;
    bool questItem;

public:
    Item();

    Item(string n, string t, int v, bool q);

    string getName();
    string getType();
    int getValue();
    bool isQuestItem();

    void display();
};

#endif