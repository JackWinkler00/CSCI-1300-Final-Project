#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character
{
protected:
    string name;
    //Need to work on a text file system to select characters with stats, use the fellowship characters
    int health;
    string location;

public:
    Character();
    Character(string n, int h, string l);

    void setName(string n);
    string getName();

    void setLocation(string l);
    string getLocation();

    virtual void talk();
};

#endif