#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "Enemy.h"
#include "Enemy.h"

using namespace std;
using std::vector;

class Room
{
    private:
        string description;
        bool unlocked = true;
        map<string, Room*> exits;
        string exitString();
        vector <Item> itemsInRoom;
    //    vector <Enemy> enemiesInRoom;
    public:
        Room(string description);
        void setDescription(string str);
        string getDescription();
        string longDescription();
        Room* nextRoom(string direction);
        void setExits(Room* north, Room* east, Room* south, Room* west);

        void setStatus(bool b);
        bool getStatus();


        void addItem(Item *inItem);
        Item* getItem();
        bool isItemInRoom(string inString);
        string displayItem();
        void removeItem();
        int getNumberOfItems();

    /*    void addEnemy(Enemy enem);
        void removeEnemy(Enemy enem);
        bool isEnemy();*/
};
#endif
