#include "Enemy.h"

Enemy::Enemy()
{

}
Enemy::Enemy(string shortDesc)
{
    this->description = shortDesc;
}

string Enemy::getLocation()
{
    return path.at(currentIndex);
}

void Enemy::addPath(vector <string> str)
{
    for(unsigned int i=0; i<str.size(); i++)
    {
        path.push_back(str.at(i));
    }
}

void Enemy::move()
{
    if(rand() % 2)
    {
        // Move forward in path
        if(currentIndex == (path.size() - 1))
        {
            currentIndex = 0;
        }
        else
        {
            currentIndex++;
        }
        //return 1;
    }
    else
    {
        // Move back in path
        if(currentIndex == 0)
        {
            currentIndex = path.size() - 1;
        }
        else
        {
            currentIndex --;
        }
        //return 0;
    }
}

string Enemy::getDescription()
{
    return description;
}

int Enemy::getPathSize()
{
    return path.size();
}

void Enemy::setLocation(int l)
{
    currentIndex = l;
}
