#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Item.h"
#include <vector>

using namespace std;

class Player : public Character
{
private:
    int stamina;
    int gold;
    int corruption;
    int turn;

    vector<Item> inventory;

public:
    Player();

    void displayStats();

    void increaseTurn();
    int getTurn();

    void move(string newLocation);

    void addItem(Item item);
    void displayInventory();

    bool hasItem(string itemName);

    int getStamina();
    int getGold();
    int getCorruption();

    void changeStamina(int amount);
    void changeGold(int amount);
    void increaseCorruption(int amount);

    void talk();

    void removeItem(string itemName);
};

#endif