#ifndef BUNDLE_H
#define BUNDLE_H

#include <string>
using namespace std;

class Bundle
{
private:
    bool cloak;
    bool sting;
    bool armor;
    bool ring;
    bool hand;

public:
    Bundle();

    void donateItem(string itemName);

    void displayBundle();

    bool isComplete();
};

#endif