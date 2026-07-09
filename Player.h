#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
private:
    int stamina;
    int gold;
    int corruption;
    int turn;

public:
    Player();

    void displayStats();

    void increaseTurn();

    int getTurn();

    void move(string location);
};

#endif