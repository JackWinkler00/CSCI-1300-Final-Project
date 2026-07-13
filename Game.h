#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Location.h"
#include <vector>

using namespace std;

class Game
{
private:
    Player player;
    bool running;

    vector<Character> characters;
    vector<Location> locations;

public:
    Game();

    void start();

    void loadCharacters();

    void createLocations();

    void displayDashboard();

    void displayMap();

    void menu();

    void processChoice(int choice);

    void movePlayer();

    void talkToCharacter();

    void searchLocation();

    void endTurn();

    void endGame();
};

#endif