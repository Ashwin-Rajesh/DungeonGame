#include "Character.h"

void Character::setDescription(string desc)
{
   description = desc;
}

void Character::addItem(Item *item)
{
    inHand.push_back(item);
}

string Character::getDescription()
{
    string str = description + "\n";
    return str;
}

int Character::inHandSize()
{
    return inHand.size();
}

void Character::useItem()
{
    inHand.empty();
}

void Character::showInHand()
{
    for(unsigned int i=0; i<inHand.size(); i++)
    {
        cout<<"Key: "<<i<<"\t";
    }
}

Item* Character::loseItem()
{
    if(inHand.empty())
    {
        return NULL;
    }
    Item* it = inHand.at(inHandSize()-1);
    inHand.pop_back();
    return it;
}

void Character::setHealth(int h)
{
    health = h;
}

int Character::getHealth()
{
    return health;
}

bool Character::getRecentlyHit()
{
    return recentlyHit;
}

void Character::setRecentlyHit(bool b)
{
    recentlyHit = b;
}
