#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;


Game::Game()
{
    //Initalizing
    running = true;
    corruptionLimit = 50;
    eyeUnlocked = false;
    hasRing = false;

    loadCharacters();
    createLocations();

    player.addItem(Item("Lembas Bread", "Food", 10, false));
}

//Main title menu
void Game::start()
{
    cout << "====================================" << endl;
    cout << "     THE QUEST OF MOUNT DOOM     " << endl;
    cout << "====================================" << endl;

    cout << "The One Ring must be destroyed." << endl;
    cout << "You must reach Mordor before Sauron is rebuilt." << endl;

    while (running)
    {
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

//Creates each location and gives it a description
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
        Item("The Hand of Sauron", "Goal Item", 0, true)
    );


    locations.push_back(shire);
    locations.push_back(rivendell);
    locations.push_back(moria);
    locations.push_back(mordor);
}

//Checker for corrutption
void Game::checkCorruption()
{
    if(player.getCorruption() >= corruptionLimit)
    {
        cout << "\nThe Ring's corruption has consumed you..." << endl;
        cout << "You have fallen under the influence of Sauron." << endl;
        cout << "\n\nYou take one last look at the fellowship as you decend into madness..." << endl;

        running = false;
    }
}

void Game::displayDashboard()
{
    cout << "\n====================================" << endl;
    cout << "        THE FINAL JOURNEY            " << endl;
    cout << "====================================" << endl;


    player.displayStats();


    displayMap();


    cout << endl;
}

//This is the map that the caracter will take on thier quest
void Game::displayMap()
{
    cout << "\nMAP:" << endl;

    cout << "[Shire] ---- [Rivendell]" << endl;
    cout << "                 |" << endl;
    cout << "              [Moria]" << endl;
    cout << "                 |" << endl;
    cout << "              [Mordor]" << endl;
}

//Menu that appears after every turn
void Game::menu()
{
    int choice;


    cout << "\nWhat would you like to do?" << endl;
    cout << "1. View player stats" << endl;
    cout << "2. View map" << endl;
    cout << "3. Travel" << endl;
    cout << "4. Search location" << endl;
    cout << "5. View inventory" << endl;
    cout << "6. View Fellowship Quest" << endl;
    cout << "7. Donate item" << endl;
    cout << "8. View companions" << endl;
    cout << "9. End turn" << endl;
    cout << "10. Quit" << endl;
    if(eyeUnlocked)
    {
    cout << "11. Use the All Seeing Eye shortcut" << endl;
    }
    cout << "\n> ";


    cin >> choice;


    processChoice(choice);
}


void Game::processChoice(int choice)
{
    switch(choice)
{
    case 1:
            player.displayStats();
            break;

        case 2:
            displayMap();
            break;

        case 3:
            movePlayer();
            player.increaseCorruption(1);
            break;

        case 4:
            searchLocation();
            player.increaseCorruption(1);
            break;

        case 5:
            player.displayInventory();
            break;

        case 6:
            bundle.displayBundle();
            break;

        case 7:
            donateItem();
            break;

        case 8:
            talkToCharacter();
            break;

        case 9:
            endTurn();
            player.increaseCorruption(2);
            break;

        case 10:
            running = false;
            break;

        case 11:
            if(eyeUnlocked)
            {
                useEyeShortcut();
                player.increaseCorruption(5);
            }
            else
            {
             cout << "You do not know about this shortcut yet." << endl;
             player.increaseCorruption(2);
             }
            break;

        default:
            cout << "Invalid choice." << endl;
}

    player.increaseCorruption(1);

    checkCorruption();
}

void Game::donateItem()
{
    player.displayInventory();

    cout << "\nEnter the name of the item to donate: ";

    cin.ignore();

    string itemName;
    getline(cin, itemName);

    if(player.hasItem(itemName))
    {
        bundle.donateItem(itemName);
        //Removes the item after it is donated, to resolve duplication
        player.removeItem(itemName);

        cout << "\n" << itemName << " added to the Fellowship Quest.\n";
    }
    else
    {
        //Message retuned if the item does not exist
        cout << "\nYou don't have that item.\n";
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

//Add location names and descriptions after the player travels there
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


void Game::talkToCharacter()
{
    cout << "\nChoose a companion:\n";
    

    for(int i = 0; i < characters.size(); i++)
    {
        cout << i + 1 << ". "
             << characters[i].getName()
             << endl;
    }

    int choice;
    cout << "\n> \n";
    cin >> choice;


    if(choice > 0 && choice <= characters.size())
    {
        //Choice - 1 is used here as we are speaking in terms of vectors, since the choices
        //start at 1, we need to subtract one to bring it in range
        characters[choice - 1].talk();

        characters[choice - 1].increaseFriendship(1);

        //Gollum's special character line
    if(characters[choice - 1].getName() == "Gollum")
{
    if(hasRing == false)
    {
        cout << "\nGollum whispers:" << endl;
        cout << "\"What has roots as nobody sees...\" " << endl;

        string answer;

        cout << "\nSolve the riddle: ";
        cin.ignore();
        getline(cin, answer);


        if(answer == "mountain" || answer == "Mountain")
        {
            cout << "\nGollum hisses..." << endl;
            cout << "\"Yes... yes... clever Hobbit!\" " << endl;

            cout << "\nGollum gives you the One Ring." << endl;

            //If the player answers right, the ring is added to the inventory
            player.addItem(
                Item("The One Ring", "Quest Item", 0, true)
            );

            hasRing = true;
        }
        else
        {
            //If the player answers wrong, Gollum runs away and the player does not get the ring
            cout << "\nGollum becomes angry and runs away." << endl;
        }
    }
    else
    {
        //Check for if the player already has the ring
        cout << "\nGollum says: \"You already have it... my precious.\"" << endl;
    }
}
        //Gandalf's special character line
        if(characters[choice - 1].getName() == "Gandalf")
        {
            if(eyeUnlocked == false)
            {
                cout << "\n\n ------** Gandalf hands you an orb **------\n" << endl;
                cout << "A gaze into this all seeing eye will great you great benefit!" << endl;
                cout << "But be wary, Sauron will corupt your mind, do not let him!" << endl;

                eyeUnlocked = true;
            }
        }
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}

void Game::useEyeShortcut()
{
    cout << "\nThe All Seeing Eye reaches across Middle Earth..." << endl;
    cout << "A dark path opens toward Mordor." << endl;

    cout << "\nYou take the shortcut, but the Ring grows heavier." << endl;

    player.move("Mordor");

    player.increaseCorruption(3);

    cout << "Corruption increased by 3." << endl;
}

//Fixed
void Game::searchLocation(){
    for(int i = 0; i < locations.size(); i++)
    {
        if(locations[i].getName() == player.getLocation())
        {
            Item found = locations[i].searchForItem();

            //Checks to see if the player has already searched this location, "Unknown" is the default name
            if (found.getName() == "Unknown")
            {
                cout << "\nThere are no more items at this location." << endl;
                return;
            }

            cout << "\nYou found: " << found.getName() << "\n";

            player.addItem(found);

            //Menu for navagation item stats
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
    //Win condition!
    if(bundle.isComplete())
    {
    cout << "\nThe Fellowship has everything needed!" << endl;
    cout << "You reach Mount Doom and destroy the One Ring!" << endl;
    cout << "Peace be upon the land, the darkness falls." << endl;
    cout << "\n\nThe Fellowship disbands." << endl;

    running = false;
}
}



void Game::endGame()
{
    cout << "\n====================================" << endl;
    cout << "           GAME OVER                  " << endl;
    cout << "====================================" << endl;

    cout << "The journey has ended." << endl;
}