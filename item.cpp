#include "item.h"

Item::Item(string inDescription)
{
    description = inDescription;
}

string Item::getShortDescription()
{
    return description;
}

