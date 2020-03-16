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
        vector <Item*> inHand;
        int health = 5;
        bool recentlyHit = false;
    public:
        void setDescription(string desc);
        string getDescription();
        void addItem(Item* item);
        Item* loseItem();
        void useItem();
        int inHandSize();
        void showInHand();
        void setHealth(int h);
        int getHealth();
        bool getRecentlyHit();
        void setRecentlyHit(bool b);
};
#endif /*CHARACTER_H_*/
