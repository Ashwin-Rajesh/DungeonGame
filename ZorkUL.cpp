#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;
#include"ZorkUL.h"

int main()
{
    ZorkUL temp;
    temp.play();
    return 0;
}

ZorkUL::ZorkUL()
{
    cout<<"***Start***"<<endl;
    cout<<"Hello Agent, you have to get to Room:Z"<<endl;
    cout<<"Please know that you have to find 3 keys to unlock Room:Z"<<endl;
    cout<<"And you might want to mind the enemies roaming around"<<endl;
    cout<<"You can use the map to know where the enemies are"<<endl;
    cout<<"Good luck on your mission, Agent Tom."<<endl<<endl;
    createWorld();
}

void ZorkUL::createWorld()
{
    //ROOMS
    Room *a, *b, *c, *d, *e;
    Room *f, *g, *h, *i, *j;
    Room *k, *l, *m, *n, *o;
    Room *p, *q, *r, *s, *t;
    Room *u, *v, *w, *x, *y, *z;

    a = new Room("A"); b = new Room("B"); c = new Room("C"); d = new Room("D");
    e = new Room("E"); f = new Room("F"); g = new Room("G"); h = new Room("H");
    i = new Room("I"); j = new Room("J"); k = new Room("K"); l = new Room("L");
    m = new Room("M"); n = new Room("N"); o = new Room("O"); p = new Room("P");
    q = new Room("Q"); r = new Room("R"); s = new Room("S"); t = new Room("T");
    u = new Room("U"); v = new Room("V"); w = new Room("W"); x = new Room("x");
    y = new Room("Y"); z = new Room("Z"); z->setStatus(false);//Room Z locked

    //         (N   , E   , S   , W   )
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
    roomList.push_back(a); roomList.push_back(b); roomList.push_back(c);
    roomList.push_back(d); roomList.push_back(e); roomList.push_back(f);
    roomList.push_back(g); roomList.push_back(h); roomList.push_back(i);
    roomList.push_back(j); roomList.push_back(k); roomList.push_back(l);
    roomList.push_back(m); roomList.push_back(n); roomList.push_back(o);
    roomList.push_back(p); roomList.push_back(q); roomList.push_back(r);
    roomList.push_back(s); roomList.push_back(t); roomList.push_back(u);
    roomList.push_back(v); roomList.push_back(w); roomList.push_back(x);
    roomList.push_back(y); roomList.push_back(z); //rooms added to list

    currentRoom = a;
    spawnRoom = a;
    exitRoom = z;

    //CHARACTER
    tom.setDescription("Agent Tom Reporting...");

    //ENEMIES

    //ITEMS
    vector<Item> keyList;
    keyList.empty();
    Item key1("key1");
    Item key2("key2");
    Item key3("key3");
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
            if(roomList.at(check) != spawnRoom && roomList.at(check)->getNumberOfItems() == 0)
            {
                roomList.at(check)->addItem(&keyList.at(i));
                cout<<"Key"<<i+1<<" is in Room: "<<roomList.at(check)->shortDescription()<<endl;
                temp = false;
            }
        }
        temp = true;
    }
}

void ZorkUL::play()
{
    cout<<"\n\nType info for help"<<endl;
    cout<<tom.getDescription()<<currentRoom->longDescription()<<endl;

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
    cout<<endl;
    cout<<"The End"<<endl;
}

bool ZorkUL::processCommand(Command command)
{
    if (command.isUnknown())
    {
        cout<<"Invalid Input"<<endl;
		return false;
    }
    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
    {
		printHelp();
    }
    else if (commandWord.compare("map") == 0)
    {
        cout<<"[A] --- [B] --- [C] --- [D] --- [E]"<<endl;
        cout<<" |               |               | "<<endl;
        cout<<" |               |               | "<<endl;
        cout<<"[F]     [G] --- [H] --- [I]     [J]"<<endl;
        cout<<" |       |       |       |       | "<<endl;
        cout<<" |       |       |       |       | "<<endl;
        cout<<"[K] --- [L] --- [M] --- [N] --- [O]"<<endl;
        cout<<" |       |       |       |       | "<<endl;
        cout<<" |       |       |       |       | "<<endl;
        cout<<"[P]     [Q] --- [R] --- [S]     [T]"<<endl;
        cout<<" |               |               | "<<endl;
        cout<<" |               |               | "<<endl;
        cout<<"[U] --- [V] --- [W] --- [X] --- [Y] --- [Z]"<<endl;
    }
//    else if (commandWord.compare("go") == 0)
//    {
//		goRoom(command);
//    }
    else if(commandWord.compare("inventory") == 0)
    {
        tom.showInHand();
        cout<<endl;
    }
    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord())
        {
            cout<<"Incomplete Input"<<endl;
        }
        else if (command.hasSecondWord())
        {
            if (currentRoom->getNumberOfItems() <=0 )
            {
                cout<<"Item is not in room"<<endl;
            }
            else
            {
                cout<<"Item is in Room: "<<currentRoom->shortDescription()<<endl;
                cout<<"Picking up" + command.getSecondWord()<<endl;
                tom.addItem(currentRoom->getItem());
                tom.showInHand();
                //cout<<tom.inHandSize()<<endl;
                currentRoom->removeItem();
            }
            cout<<currentRoom->longDescription()<<endl;
        }
    }
    else if(commandWord.compare("unlock") == 0)
    {
        if(currentRoom != roomList.at(24))
        {
            cout<<"You have to get to Room: y"<<endl;
        }
        else if(currentRoom == roomList.at(24))
        {
            if(tom.inHandSize() == 3)
            {
                exitRoom->setStatus(true);
                tom.useItem();
                //cout<<exitRoom->getStatus()<<endl;
            }
            else
            {
                cout<<"You need "<<3-tom.inHandSize()<<" more key/s"<<endl;
            }
        }
    }

    else if (commandWord.compare("w") == 0 || commandWord.compare("W") == 0)
    {
        go("w");
    }
    else if (commandWord.compare("a") == 0 || commandWord.compare("A") == 0)
    {
        go("a");
    }
    else if (commandWord.compare("s") == 0 || commandWord.compare("S") == 0)
    {
        go("s");
    }
    else if (commandWord.compare("d") == 0 || commandWord.compare("D") == 0)
    {
        go("d");
    }

    else if (commandWord.compare("quit") == 0)
    {
		if (command.hasSecondWord())
        {
            cout << "Overdefined Input"<< endl;
        }
		else
        {
			return true; /**signal to quit*/
        }
	}
	return false;
}

void ZorkUL::printHelp()
{
    cout << "Valid inputs are; " << endl;
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
    return("Teleporting...\n" + tom.getDescription() + currentRoom->longDescription() + "\n");
}

int ZorkUL::randomRoomSelection()
{
    int r = 0;
    srand (time(NULL));
    r = rand() % 25;
    return r;
}

void ZorkUL::go(string direction)
{
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
    {
        cout<<"Underdefined Input"<<endl;
    }
    else
    {
        if(nextRoom != exitRoom)
        {
            currentRoom = nextRoom;
            cout<<endl<<tom.getDescription()<<currentRoom->longDescription()<<endl;
        }
        else
        {
            if(exitRoom->getStatus())
            {
                currentRoom = exitRoom;
                cout<<tom.getDescription()<<currentRoom->longDescription()<<endl;
            }
            else
            {
                cout<<"Use the keys to unlock the room"<<endl;
            }
        }
    }
}
