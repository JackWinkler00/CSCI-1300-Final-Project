#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item
{
private:
    string name;
    string type;

public:
    Item();
    Item(string n, string t);

    string getName();

    string getType();

    void display();
};

#endif