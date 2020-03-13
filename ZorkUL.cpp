#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
#include "ZorkUL.h"

int main(/*int argc, char argv[]*/)
{
    ZorkUL temp;
    temp.play();
    return 0;
}

ZorkUL::ZorkUL()
{
    createWorld();
}

void ZorkUL::createWorld()
{
    Room *a, *b, *c, *d, *e;
    Room *f, *g, *h, *i, *j;
    Room *k, *l, *m, *n, *o;
    Room *p, *q, *r, *s, *t;
    Room *u, *v, *w, *x, *y, *z;

	a = new Room("a");
	b = new Room("b");
	c = new Room("c");
	d = new Room("d");
	e = new Room("e");
	f = new Room("f");
	g = new Room("g");
	h = new Room("h");
	i = new Room("i");
    j = new Room("j");
    k = new Room("k");
    l = new Room("l");
    m = new Room("m");
    n = new Room("n");
    o = new Room("o");
    p = new Room("p");
    q = new Room("q");
    r = new Room("r");
    s = new Room("s");
    t = new Room("t");
    u = new Room("u");
    v = new Room("v");
    w = new Room("w");
    x = new Room("x");
    y = new Room("y");
    z = new Room("z");
    z->setStatus(false);

    //(N, E, S, W)
    a->setExits(NULL, b,    f,    NULL);
    b->setExits(NULL, c,    NULL, a);
    c->setExits(NULL, d,    h,    b);
    d->setExits(NULL, e,    NULL, c);
    e->setExits(NULL, NULL, j,    d);
    f->setExits(a,    NULL, k,    NULL);
    g->setExits(NULL, h,    l,    NULL);
    h->setExits(c,    i,    m,    g);
    i->setExits(NULL, NULL, n,    h);
    j->setExits(e,    NULL, o,    NULL);
    k->setExits(f,    l,    p,    NULL);
    l->setExits(g,    m,    q,    k);
    m->setExits(h,    n,    r,    l);
    n->setExits(i,    o,    s,    m);
    o->setExits(j,    NULL, t,    n);
    p->setExits(k,    NULL, u,    NULL);
    q->setExits(l,    r,    NULL, NULL);
    r->setExits(m,    s,    w,    q);
    s->setExits(n,    NULL, NULL, s);
    t->setExits(o,    NULL, y,    NULL);
    u->setExits(p,    v,    NULL, NULL);
    v->setExits(NULL, w,    NULL, u);
    w->setExits(r,    x,    NULL, v);
    x->setExits(NULL, y,    NULL, w);
    y->setExits(t,    z,    NULL, x);


    roomList.empty();
    roomList.push_back(a);
    roomList.push_back(b);
    roomList.push_back(c);
    roomList.push_back(d);
    roomList.push_back(e);
    roomList.push_back(f);
    roomList.push_back(g);
    roomList.push_back(h);
    roomList.push_back(i);
    roomList.push_back(j);
    roomList.push_back(k);
    roomList.push_back(l);
    roomList.push_back(m);
    roomList.push_back(n);
    roomList.push_back(o);
    roomList.push_back(p);
    roomList.push_back(q);
    roomList.push_back(r);
    roomList.push_back(s);
    roomList.push_back(t);
    roomList.push_back(u);
    roomList.push_back(v);
    roomList.push_back(w);
    roomList.push_back(x);
    roomList.push_back(y);
    roomList.push_back(z);

    currentRoom = a;
    spawnRoom = a;
    exitRoom = z;
    Room* test;

    vector<Item> keyList;
    keyList.empty();
    Item key1("KEYI");
    Item key2("KEYII");
    Item key3("KEYIII");
    keyList.push_back(key1);
    keyList.push_back(key2);
    keyList.push_back(key3);

    bool temp = true;
    int check = 0;
    for(int i=0; i<3; i++)
    {
        while(temp)
        {
            check = randomRoomSelection();
            test = roomList.at(check);
            if(test != spawnRoom && test->numberOfItems() == 0)
            {
                roomList.at(check)->addItem(&keyList.at(i));
                cout<<roomList.at(check)->longDescription()<<endl;
                cout<<roomList.at(check)->numberOfItems()<<endl;
                temp = false;
            }
        }
        temp = true;
    }
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play()
{
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
    while (!finished)
    {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

void ZorkUL::printWelcome()
{
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command)
{
    if (command.isUnknown())
    {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
    {
        cout << "[a] --- [b] --- [c] --- [d] --- [e]" << endl;
        cout << " |               |               | " << endl;
        cout << " |               |               | " << endl;
        cout << "[f]     [g] --- [h] --- [i]     [j]" << endl;
        cout << " |       |       |       |       | " << endl;
        cout << " |       |       |       |       | " << endl;
        cout << "[k] --- [l] --- [m] --- [n] --- [o]" << endl;
        cout << " |       |       |       |       | " << endl;
        cout << " |       |       |       |       | " << endl;
        cout << "[p]     [q] --- [r] --- [s]     [t]" << endl;
        cout << " |               |               | " << endl;
        cout << " |               |               | " << endl;
        cout << "[u] --- [v] --- [w] --- [x] --- [y] --- [z]" << endl;
    }
    else if(commandWord.compare("teleport") == 0)
    {
        cout<<teleport();
    }

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord())
        {
            cout << "incomplete input"<< endl;
        }
        else if (command.hasSecondWord())
        {
            cout << "you're trying to take " + command.getSecondWord() << endl;
            int location = currentRoom->isItemInRoom(command.getSecondWord());
            if (location  < 0 )
                cout << "item is not in room" << endl;
            else
                cout << "item is in room" << endl;
                cout << "index number " << + location << endl;
                cout << endl;
                cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
/*
{
    if (!command.hasSecondWord())
    {
		cout << "incomplete input"<< endl;
    }
    else if (command.hasSecondWord())
    {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
    }
}
*/
    else if (commandWord.compare("quit") == 0)
    {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp()
{
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}
string ZorkUL::teleport()
{
    bool temp = true;
    Room* teleportRoom;
    while(temp)
    {
        teleportRoom = roomList.at(randomRoomSelection());
        if(teleportRoom != currentRoom && teleportRoom != exitRoom)
        {
            temp = false;
            currentRoom=teleportRoom;
        }
    }
    return("teleporting...\n" + currentRoom->longDescription() + "\n");
}

int ZorkUL::randomRoomSelection()
{
    int r = 0;
    //Room* teleportRoom;
    srand (time(NULL));
    r = rand() % 25;
    return r;
}

string ZorkUL::goRoom(Command command)
{
    if (!command.hasSecondWord())
    {
		cout << "incomplete input"<< endl;
        return "incomplete input";
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
    {
		cout << "underdefined input"<< endl;
        return("underdefined input");
    }
    else
    {
        if(nextRoom != exitRoom)
        {
            currentRoom = nextRoom;
            cout << currentRoom->longDescription() << endl;
        }
        else
        {
            //check if the player has 3 keys
        }
	}
    return(currentRoom->longDescription() + "\n");
}

string ZorkUL::go(string direction)
{
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
