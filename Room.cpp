#include "Room.h"
#include "Command.h"

Room::Room(string description)
{
    this->description = description;
}

void Room::setExits(Room *up, Room *right, Room *down, Room *left)
{
    if(up != NULL)
        exits["w"] = up;
    if(right != NULL)
        exits["d"] = right;
    if(down != NULL)
        exits["s"] = down;
    if(left != NULL)
        exits["a"] = left;
}

void Room::setStatus(bool b)
{
    this->unlocked = b;
}

bool Room::getStatus()
{
    return unlocked;
}

string Room::getDescription()
{
    return description;
}

string Room::longDescription()
{
    return "Room: [" + description + "]\n" + displayItem() + "\n";
}

string Room::exitString()
{
    string returnString = "\nExits: ";
    for(map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)// Loop through map
    {
        if(i->first.compare("w") == 0)
            returnString += "UP  ";
        else if(i->first.compare("a") == 0)
            returnString += "LEFT  ";
        else if(i->first.compare("s") == 0)
            returnString += "DOWN  ";
        else if(i->first.compare("d") == 0)
            returnString += "RIGHT  ";
    }
    return returnString + "\n";
}

Room* Room::nextRoom(string direction)
{
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if(next == exits.end())
    {
        return NULL; // if exits.end() was returned, there's no room in that direction.
    }
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem)
{
    itemsInRoom.push_back(*inItem);
}

string Room::displayItem()
{
    string tempString = "Items in Room: ";
    if(itemsInRoom.size() < 1)
    {
        tempString = "No keys here";
    }
    else if(itemsInRoom.size() > 0)
    {
        tempString = tempString + itemsInRoom[0].getDescription() + "  " ;
    }
    return tempString;
}

int Room::getNumberOfItems()
{
    return itemsInRoom.size();
}

bool Room::isItemInRoom()
{
    if(itemsInRoom.size() < 1)
    {
        return false;
    }
    else if(itemsInRoom.size() > 0)
    {
        return true;
    }
    return false;
}

Item* Room::getItem()
{
    return &itemsInRoom.at(0);
}

void Room::removeItem()
{
    itemsInRoom.pop_back();
}

void Room::setDescription(string str)
{
    description = str;
}
