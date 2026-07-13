#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;


Game::Game()
{
    running = true;

    loadCharacters();
    createLocations();

    player.addItem(Item("Lembas Bread", "Food", 10, false));
    player.addItem(Item("The One Ring", "Quest Item", 0, true));
    //This is the ring, the quest item tag makes it a quest item, 0 is used here for value so players won't try to sell it
}


void Game::start()
{
    cout << "====================================" << endl;
    cout << "     THE QUEST OF MOUNT DOOM     " << endl;
    cout << "====================================" << endl;

    cout << "The One Ring must be destroyed." << endl;
    cout << "You must reach Mordor before Sauron is rebuilt." << endl;

    while (running)
    {
        displayDashboard();
        menu();
    }

    endGame();
}


void Game::loadCharacters()
{
    ifstream file("characters.txt");

    if (!file.is_open())
    {
        cout << "Could not open character file." << endl;
        return;
    }
    //Checks if the file is NOT open, if it isnt, it returns the error message


    string name;
    int health;
    string location;


    while (file >> name >> health >> location)
    {
        Character character(name, health, location);
        characters.push_back(character);
    }

    file.close();
    //Bet you can guess what this one does
}


void Game::createLocations()
{
    Location shire(
        "The Shire",
        "A peaceful land where the journey begins.",
        true
    );


    Location rivendell(
        "Rivendell",
        "The home of Elrond and the elves.",
        true
    );


    Location moria(
        "Moria",
        "A dark underground path filled with danger.",
        true
    );


    Location mordor(
        "Mordor",
        "The land of shadows where the Ring must be destroyed.",
        true
    );


    shire.addItem(
        Item("Elven Cloak", "Equipment", 25, true)
    );


    rivendell.addItem(
        Item("Sting", "Weapon", 50, true)
    );


    moria.addItem(
        Item("Mithril Armor", "Armor", 100, true)
    );


    mordor.addItem(
        Item("Mount Doom", "Goal Item", 0, true)
    );


    locations.push_back(shire);
    locations.push_back(rivendell);
    locations.push_back(moria);
    locations.push_back(mordor);
}

//Change this to not appear every time
void Game::displayDashboard()
{
    cout << "\n====================================" << endl;
    cout << "        THE FINAL JOURNEY            " << endl;
    cout << "====================================" << endl;


    player.displayStats();


    displayMap();


    cout << endl;
}

//Make this a menu option, don't have it appear every time
void Game::displayMap()
{
    cout << "\nMAP:" << endl;

    cout << "[Shire] ---- [Rivendell]" << endl;
    cout << "                 |" << endl;
    cout << "              [Moria]" << endl;
    cout << "                 |" << endl;
    cout << "              [Mordor]" << endl;
}


void Game::menu()
{
    int choice;


    cout << "\nWhat would you like to do?" << endl;
    cout << "1. Travel" << endl;
    cout << "2. Search location" << endl;
    cout << "3. View inventory" << endl;
    cout << "4. View companions" << endl;
    cout << "5. End turn" << endl;
    cout << "6. Quit" << endl;
    cout << "\n> ";


    cin >> choice;


    processChoice(choice);
}


void Game::processChoice(int choice)
{
    switch(choice)
    {
        case 1:
            movePlayer();
            break;

        case 2:
            searchLocation();
            break;

        case 3:
            player.displayInventory();
            break;

        case 4:
            talkToCharacter();
            break;

        case 5:
            endTurn();
            break;

        case 6:
            running = false;
            break;

        default:
            cout << "Invalid choice." << endl;
            cout << "\n> ";
    }
}


void Game::movePlayer()
{
    cout << "\nWhere do you want to travel?" << endl;

    cout << "1. The Shire" << endl;
    cout << "2. Rivendell" << endl;
    cout << "3. Moria" << endl;
    cout << "4. Mordor" << endl;
    cout << "\n> ";


    int choice;
    cin >> choice;

//Add location names and descriptions after the player travles there
    if(choice == 1)
    {
        player.move("The Shire");
    }
    else if(choice == 2)
    {
        player.move("Rivendell");
    }
    else if(choice == 3)
    {
        player.move("Moria");
    }
    else if(choice == 4)
    {
        player.move("Mordor");
    }
    else
    {
        cout << "Invalid location." << endl;
    }
    Game::endTurn();
    //Maybe change this to have it's own custom response, like, you traveled so far or something
}

//This has the same problem as the search location function did, as of now only Gandalf exists lmao
void Game::talkToCharacter()
{
    if(characters.size() > 0)
    {
        cout << "\nYou meet " 
             << characters[0].getName()
             << endl;

        characters[0].talk();

        characters[0].increaseFriendship(1);
    }
    else
    {
        cout << "No companions nearby." << endl;
    }
}

//Bugged, if the player searches the same location twice, fix that
void Game::searchLocation(){
    for(int i = 0; i < locations.size(); i++)
    {
        if(locations[i].getName() == player.getLocation())
        {
            Item found = locations[i].searchForItem();

            cout << "\nYou found: " << found.getName() << "\n";

            player.addItem(found);

            cout << "\nWould you like to view the stats?";
            cout << "\n y. Yes";
            cout << "\n n. No\n\n> ";
            string yesOrNo;
            cin >> yesOrNo;
            if(yesOrNo == "y"){
                found.display();
            }
            else
            if(yesOrNo == "n"){
                return;
            }
            else{
                cout << "\nInvalid choice";
            }

            return;
        }
    }

    cout << "There are no items here." << endl;
}


void Game::endTurn()
{
    player.increaseTurn();
//Add a random element that gives different responses
    cout << "\nThe day ends..." << endl;


    if(player.getTurn() >= 20)
    {
        running = false;
    }
}

//Add win condition/complete game ending

void Game::endGame()
{
    cout << "\n====================================" << endl;
    cout << "          GAME OVER                  " << endl;
    cout << "====================================" << endl;

    cout << "The journey has ended." << endl;
}