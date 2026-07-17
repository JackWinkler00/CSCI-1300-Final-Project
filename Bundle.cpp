#include "Bundle.h"
#include <iostream>

using namespace std;
//Constructor, sets every value to false starting, as the character has none of the items
Bundle::Bundle()
{
    cloak = false;
    sting = false;
    armor = false;
    ring = false;
    hand = false;
}

void Bundle::donateItem(string itemName)
{
    //If you have the cloak, cloak becomes true (filled)
    if(itemName == "Elven Cloak")
        cloak = true;
    //If you have sting, sting becomes true (filled)
    else if(itemName == "Sting")
        sting = true;
    //The pattern repeats
    else if(itemName == "Mithril Armor")
        armor = true;
    //Same thing here
    else if(itemName == "The One Ring")
        ring = true;
    else if(itemName == "The Hand of Sauron")
        hand = true;
}

void Bundle::displayBundle()
{
    cout << "\n===== FELLOWSHIP QUEST =====\n";

    //Checks the bool value of cloak
    if(cloak)
    {
        //If you have it, it appears checked
        cout << "[X] Elven Cloak\n";
    }
    else
    {
        //If you don't, it appears unchecked
        cout << "[ ] Elven Cloak\n";
    }


    if(sting)
    {
        //Found by searching 
        cout << "[X] Sting\n";
    }
    else
    {
        cout << "[ ] Sting\n";
    }


    if(armor)
    {
        cout << "[X] Mithril Armor\n";
    }
    else
    {
        cout << "[ ] Mithril Armor\n";
    }


    if(ring)
    {
        cout << "[X] The One Ring\n";
    }
    else
    {
        cout << "[ ] The One Ring\n";
    }

    if(hand)
    {
        cout << "[X] The Hand of Sauron\n";
    }
    else
    {
        cout << "[ ] The Hand of Sauron\n";
    }

    int progress = 0;

    if(cloak)
    {
        progress++;
    }

    if(sting)
    {
        progress++;
    }

    if(armor)
    {
        progress++;
    }

    if(ring)
    {
        progress++;
    }

     if(hand)
    {
        progress++;
    }

    cout << "\nProgress: " << progress << "/5\n";
}

//This is the check for the completed bundle, aka the end of the game
bool Bundle::isComplete()
{
    return cloak && sting && armor && ring && hand;
}