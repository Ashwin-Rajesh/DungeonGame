#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
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
    public:
        int numberOfItems();
        Room(string description);
        void setExits(Room *north, Room *east, Room *south, Room *west);
        void setStatus(bool b);
        bool getStatus();
        string shortDescription();
        string longDescription();
        Room* nextRoom(string direction);
        void addItem(Item *inItem);
        Item* getItem();
        void removeItem();
        string displayItem();
        int isItemInRoom(string inString);
        //void removeItemFromRoom(int location);
};
#endif
