#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Character.h"
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "Enemy.h"
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
        vector<Enemy*> listofEnemies;
        vector<Room*> roomList;
        void createWorld();
        bool processCommand(Command command);
        void createItems();
        void displayItems();
    public:
        string teleport();
        int randomRoomSelection();
        void enemyMove(Enemy *enem);
        void enemySpawn(Enemy *enem);
        int enemyCheck(string room);
        //void addEnemyList();
        void go(string direction);
        ZorkUL();
        void play();
        void map();
        void playerStay();
};
#endif /*ZORKUL_H_*/
