#ifndef ENEMY_H
#define ENEMY_H

#include "item.h"
#include <string>
#include <vector>
#include <random>

using namespace std;
using std::vector;

class Enemy
{
    private:
        string description;
        unsigned int currentIndex;
        vector<string> path;
    public:
        Enemy();
        Enemy(string shortDesc);
        void setDescription(string str);
        string getDescription();
        void setLocation(int l);
        string getLocation();
        void addPath(vector <string> str);
        int getPathSize();
        void move();
};
#endif
