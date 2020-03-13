#ifndef ENEMY_H
#define ENEMY_H
#include "item.h"
#include <string>
#include "Room.h"

#include <vector>
#include <random>

using namespace std;
using std::vector;

class Enemy
{
private:
    string  description;
    int currentIndex;
    vector<string> path;

public:
    Enemy(string short_desc);
    string  getLocation();
    void    move();
    void    addPath(string room);
    string  shortDescription();
};
#endif