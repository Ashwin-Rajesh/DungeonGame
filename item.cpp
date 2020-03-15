#include "item.h"

Item::Item(string inDescription)
{
    description = inDescription;
}

string Item::getDescription()
{
    return description;
}

