#include "Enemy.h"
#include "time.h"


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
vector <string> Enemy::getPath()
{
    return path;
}

void Enemy::move()
{
    int i = rand() % 3;
    if(i == 2)
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
    }
    else if(i == 0)
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
