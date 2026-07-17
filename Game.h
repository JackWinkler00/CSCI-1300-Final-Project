#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Location.h"
#include "Bundle.h"
#include <vector>

using namespace std;

class Game
{
private:
    Player player;
    bool running;

    vector<Character> characters;
    vector<Location> locations;

    Bundle bundle;

    int corruptionLimit = 50;

    //Checks if the player has talked to Gandalf to unlock the eye
    bool eyeUnlocked;

    //Checks if the player has recieved the ring from Gollum
    bool hasRing;

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

    void donateItem();

    void checkCorruption();

    void useEyeShortcut();
};

#endif