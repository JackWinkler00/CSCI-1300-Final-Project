#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game
{
private:
    Player player;
    bool running;

public:
    //for the game, interface
    Game();

    void start();

    void menu();

    void processChoice(int choice);

    void endGame();
};

#endif