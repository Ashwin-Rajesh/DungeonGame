#include "Character.h"

void Character::setDescription(string desc)
{
   description = desc;
}

void Character::addItem(Item *item)
{
    inHand.push_back(*item);
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
        cout<<inHand.at(i).getShortDescription()<<"\t";
    }
}
