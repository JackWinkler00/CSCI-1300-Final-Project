#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class Character
{
private:
    string name;
    int health;
    string location;
    int friendship;

public:
    Character();
    Character(string n, int h, string l);

    void setName(string n);
    string getName();

    void setLocation(string l);
    string getLocation();

    void setHealth(int h);
    int getHealth();
    int getFriendship();

    void increaseFriendship(int amount);

    void talk();
};

#endif