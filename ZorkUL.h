#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Character.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ZorkUL
{
    private:
        Parser parser;
        Room* currentRoom;
        Room* spawnRoom;
        Room* exitRoom;
        Character tom;
        vector<Room*> roomList;
        void createWorld();
        bool processCommand(Command command);
        void printHelp();
        void createItems();
        void displayItems();
    public:
        string teleport();
        int randomRoomSelection();
        string goRoom(Command command);
        void go(string direction);
        ZorkUL();
        void play();      
};
#endif /*ZORKUL_H_*/
