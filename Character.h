#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "item.h"
#include <string>
#include <vector>

using namespace std;
using std::vector;

class Character
{
    private:
        string description;
        vector <Item> inHand;
    public:
        void useItem();
        int inHandSize();
        void showInHand();
        void addItem(Item* item);
        void setDescription(string desc);
        string getDescription();
};
#endif /*CHARACTER_H_*/
