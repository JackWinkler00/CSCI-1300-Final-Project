#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
    setName ("Frodo");
    setHealth (100);
    setLocation ("The Shire");

    stamina = 10;
    gold = 50;
    corruption = 0;
    turn = 1;
}


void Player::displayStats()
{
    cout << "==============================" << endl;
    cout << "Player: " << getName() << endl;
    cout << "Location: " << getLocation() << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Gold: " << gold << endl;
    cout << "Corruption: " << corruption << endl;
    cout << "Turn: " << turn << "/20" << endl;
    cout << "==============================" << endl;
}


void Player::increaseTurn()
{
    turn++;
}


int Player::getTurn()
{
    return turn;
}


void Player::move(string newLocation)
{
    setLocation (newLocation);
    stamina -= 1;

    if (stamina < 0)
    {
        stamina = 0;
    }
}


void Player::addItem(Item item)
{
    inventory.push_back(item);
}


void Player::displayInventory()
{
    cout << "\nInventory:" << endl;

    if (inventory.size() == 0)
    {
        cout << " - Empty" << endl;
        return;
    }

    for (int i = 0; i < inventory.size(); i++)
    {
        cout << i + 1 << ". ";
        inventory[i].display();
    }
}


bool Player::hasItem(string itemName)
{
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].getName() == itemName)
        {
            return true;
        }
    }

    return false;
}


int Player::getStamina()
{
    return stamina;
}


int Player::getGold()
{
    return gold;
}


int Player::getCorruption()
{
    return corruption;
}


void Player::changeStamina(int amount)
{
    stamina += amount;

    if (stamina < 0)
    {
        stamina = 0;
    }
}


void Player::changeGold(int amount)
{
    gold += amount;
}


void Player::increaseCorruption(int amount)
{
    corruption += amount;
}


void Player::talk()
{
    cout << getName() << " says: I will carry this burden." << endl;
}