#ifndef CHARACTER_H_
#define CHARACTER_H
#include "item.h"
#include <string>
using namespace std;
#include <vector>
using std::vector;

class Character
{
    private:
        string description;
        //vector < string > itemsInCharacter;
        vector <Item *> inHand;
    public:
        //void addItem(Item i);
        void addItem(Item* item);
        void addItem(string Item);
        //Character(string description);
        void setDescription(string desc);
        string shortDescription();
        string longDescription();
};
#endif /*CHARACTER_H_*/