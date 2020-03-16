#include "CommandWords.h"

vector<string> CommandWords::validCommands;

CommandWords::CommandWords()
{
	// Populate the vector if we haven't already.
    if(validCommands.empty())
    {
		validCommands.push_back("go");
        validCommands.push_back("w");
        validCommands.push_back("a");
        validCommands.push_back("s");
        validCommands.push_back("d");
        validCommands.push_back("W");
        validCommands.push_back("A");
        validCommands.push_back("S");
        validCommands.push_back("D");
		validCommands.push_back("quit");
		validCommands.push_back("info");
		validCommands.push_back("map");
        validCommands.push_back("stay");
        validCommands.push_back("take");
        validCommands.push_back("unlock");
        validCommands.push_back("use");
        validCommands.push_back("inventory");
	}
}

bool CommandWords::isCommand(string aString)
{
    for(unsigned int i = 0; i < validCommands.size(); i++)
	{
        if(validCommands[i].compare(aString) == 0)
			return true;
	}
	// if we get here, the string was not found in the commands
	return false;
}

void CommandWords::showAll()
{
	//Loops through validCommands and prints each to the screen.
    for(unsigned int i = 0; i < validCommands.size(); i++)
	{
        cout<<validCommands[i]<< "  ";
	}
    cout<<endl;
}
