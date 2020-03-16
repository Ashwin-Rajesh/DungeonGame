#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item
{
    private:
        string description;
    public:
        Item (string description);
        string getDescription();
};
#endif /*ITEM_H_*/
