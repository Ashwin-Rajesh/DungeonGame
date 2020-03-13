#include "Enemy.h"

Enemy::Enemy(string desc)
{
    this->description   = desc;
}

string Enemy::getLocation()
{
    return path.at(currentIndex);
}

void Enemy::addPath(string room)
{
    path.push_back(room);
}

void Enemy::move()
{
    if(rand() % 2)
    {
        // Move forward in path
        if(currentIndex == path.size() - 1)  {currentIndex = 0;                      }
        else                                {currentIndex++;                        }
    }
    else
    {
        // Move back in path
        if(currentIndex == 0)               {currentIndex = path.size() - 1;         }
        else                                {currentIndex --;                       }

    }
}

string Enemy::shortDescription()
{
    return description;
}