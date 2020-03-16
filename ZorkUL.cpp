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
    cout<<"Hello Agent Tom, you have to get to Room:Z"<<endl;
    cout<<"Please know that you have to find 3 keys to unlock Room:Z"<<endl;
    cout<<"And you might want to mind the enemies roaming around"<<endl;
    cout<<"You can use the map to know where the enemies are"<<endl;
    cout<<"Good luck on your mission."<<endl;
    cout<<"Type info for help"<<endl<<endl;
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
    y = new Room("Y"); z = new Room("Z"); z->setStatus(false); //Room Z locked

    spawnRoom = new Room("!");
    spawnRoom->setExits(NULL,a,NULL,NULL);

    //         (W   , D   , S   , A   )
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
    exitRoom = z;

    //CHARACTER
    tom.setDescription("Agent Tom Reporting...");

    //ENEMIES
    Enemy *e1 = new Enemy("Enemy1"); Enemy *e2 = new Enemy("Enemy2");
    Enemy *e3 = new Enemy("Enemy1"); Enemy *e4 = new Enemy("Enemy2");
    Enemy *e5 = new Enemy("Enemy1"); Enemy *e6 = new Enemy("Enemy2");

    vector<string> innerSquare;
    innerSquare.push_back("G"); innerSquare.push_back("H"); innerSquare.push_back("I");
    innerSquare.push_back("N"); innerSquare.push_back("S"); innerSquare.push_back("R");
    innerSquare.push_back("Q"); innerSquare.push_back("L");

    vector<string> outerSquare;
    outerSquare.push_back("A"); outerSquare.push_back("B"); outerSquare.push_back("C"); outerSquare.push_back("D");
    outerSquare.push_back("E"); outerSquare.push_back("J"); outerSquare.push_back("O"); outerSquare.push_back("T");
    outerSquare.push_back("Y"); outerSquare.push_back("X"); outerSquare.push_back("W"); outerSquare.push_back("V");
    outerSquare.push_back("U"); outerSquare.push_back("P"); outerSquare.push_back("K"); outerSquare.push_back("F");

    srand (time(NULL));
    e1->addPath(innerSquare); listofEnemies.push_back(e1); enemySpawn(e1);
    e2->addPath(innerSquare); listofEnemies.push_back(e2); enemySpawn(e2);
    e3->addPath(outerSquare); listofEnemies.push_back(e3); enemySpawn(e3);
    e4->addPath(outerSquare); listofEnemies.push_back(e4); enemySpawn(e4);
    e5->addPath(outerSquare); listofEnemies.push_back(e5); enemySpawn(e5);
    e6->addPath(outerSquare); listofEnemies.push_back(e6); enemySpawn(e6);


    //ITEMS
    vector<Item> keyList;
    keyList.empty();

    Item key1("key1"); keyList.push_back(key1);
    Item key2("key2"); keyList.push_back(key2);
    Item key3("key3"); keyList.push_back(key3);

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
                cout<<"Key"<<i+1<<" is in Room: "<<roomList.at(check)->getDescription()<<endl;
                temp = false;
            }
        }
        temp = true;
    }
}

void ZorkUL::play()
{
    cout<<endl<<"Room: [!]"<<endl<<"Exits: "<<"RIGHT"<<endl;
    currentRoom = spawnRoom;

    bool finished = false;
    while(!finished)
    {
        Command* command = parser.getCommand();
        finished = processCommand(*command);
        delete command;
    }
    cout<<endl;
    cout<<"***The End***"<<endl;
}

bool ZorkUL::processCommand(Command command)
{
    if(command.isUnknown())
    {
        cout<<"Invalid Input"<<endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if(commandWord.compare("info") == 0)
    {
        cout<<"'WASD/wasd' to navigate,\n 'map' to view the map,\n 'inventory' to know the keys in you,\n"
              " 'take' to pick up the keys,\n 'unlock' to unlock the Room: [Z],\n 'stay' to stay where you are,\n"
              " 'use' to use the tracker to spot the enemies,\n 'quit' to quit the game\n";
    }

    else if(commandWord.compare("map") == 0)
    {
        map();
    }

    else if(commandWord.compare("inventory") == 0)
    {
        tom.showInHand();
        cout<<endl;
    }

    else if(commandWord.compare("take") == 0)
    {
        if(!command.hasSecondWord())
        {
            cout<<"Incomplete Input"<<endl;
        }
        else if(command.hasSecondWord())
        {
            if(currentRoom->getNumberOfItems() <= 0)
            {
                cout<<"Item is not in room"<<endl;
            }
            else
            {
                cout<<"Picking up" + command.getSecondWord()<<endl;
                tom.addItem(currentRoom->getItem());
                currentRoom->removeItem();
            }
            cout<<currentRoom->longDescription()<<currentRoom->exitString();
        }
    }

    else if(commandWord.compare("unlock") == 0)
    {
        if(currentRoom != roomList.at(24))
        {
            cout<<"You have to get to Room: [Y]"<<endl;
        }
        else if(currentRoom == roomList.at(24))
        {
            if(tom.inHandSize() == 3)
            {
                exitRoom->setStatus(true);
                tom.useItem();
            }
            else
            {
                cout<<"You need "<<3-tom.inHandSize()<<" more key/s"<<endl;
            }
        }
    }

    else if(commandWord.compare("w") == 0 || commandWord.compare("W") == 0)
    {
        go("w");

    }

    else if(commandWord.compare("a") == 0 || commandWord.compare("A") == 0)
    {
        go("a");

    }

    else if(commandWord.compare("s") == 0 || commandWord.compare("S") == 0)
    {
        go("s");

    }

    else if(commandWord.compare("d") == 0 || commandWord.compare("D") == 0)
    {
        go("d");

    }

    else if(commandWord.compare("stay") == 0)
    {
        playerStay();
    }

    else if(commandWord.compare("use") == 0)
    {
        if(!command.hasSecondWord())
        {
            cout<<"Incomplete Input"<<endl;
        }
        else if(command.getSecondWord().compare("tracker") == 0)
        {
            //ENEMY
            int ecount = 0;
            for(unsigned int i=0; i<listofEnemies.size(); i++)
            {
                for(unsigned int j=0; j<roomList.size(); j++)
                {
                    if(roomList.at(j)->getDescription().compare(listofEnemies.at(i)->getLocation()) == 0)
                    {
                        ecount++;
                        cout<<"Enemy:"<<i+1<<" is in Room: ["<<roomList.at(j)->getDescription()<<"]";
                        if(ecount%2 == 0)
                            cout<<endl;
                        else
                            cout<<"  ";
                    }
                }
            }
            cout<<endl;

            //ITEM
            int kcount = 1;
            for(unsigned int i=0; i<roomList.size(); i++)
            {
                if(roomList.at(i)->isItemInRoom())
                {
                    cout<<"Key:"<<kcount<<" is in Room: ["<<roomList.at(i)->getDescription()<<"]"<<endl;
                    kcount++;
                }
            }
        }
    }

    else if(commandWord.compare("quit") == 0)
    {
        if(command.hasSecondWord())
        {
            cout<<"Overdefined Input"<<endl;
        }
        else
        {
            return true;
        }
    }
    else if(tom.getHealth() == 0)
    {
        return false;
    }
    return false;
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
            currentRoom->addItem(tom.loseItem());
            temp = false;
            currentRoom=teleportRoom;
        }
    }
    return(tom.getDescription() + currentRoom->longDescription() + currentRoom->exitString());
}

int ZorkUL::randomRoomSelection()
{
    int r = 0;
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
            cout<<tom.getDescription()<<currentRoom->longDescription();
            playerStay();
            map();
            cout<<currentRoom->exitString();
            tom.setRecentlyHit(false);
        }
        else
        {
            if(exitRoom->getStatus())
            {
                currentRoom = exitRoom;
                cout<<tom.getDescription()<<"Room: Z reached";
            }
            else
            {
                cout<<"Use the keys to unlock the room"<<endl;
            }
        }
    }
}

void ZorkUL::enemySpawn(Enemy *enem)
{
    int r = rand() % enem->getPathSize();
    enem->setLocation(r);
}

int ZorkUL::enemyCheck(string room)
{
    int temp = 0;
    for(unsigned int i = 0; i<listofEnemies.size(); i++)
    {
        if(listofEnemies.at(i)->getLocation().compare(room) == 0)
        {
            temp++;
        }
    }
    return temp;
}

void ZorkUL::enemyMove(Enemy *enem)
{
    string curInd = enem->getLocation();
    string nxtInd = " ";
    enem->move();
}

void ZorkUL::playerStay()
{
    for(unsigned int i=0; i<listofEnemies.size(); i++)
    {
        enemyMove(listofEnemies.at(i));
    }
    if(enemyCheck(currentRoom->getDescription()) && !tom.getRecentlyHit())//has enemies
    {
        cout<<teleport();
        tom.setHealth(tom.getHealth() - 1);
        tom.setRecentlyHit(true);
    }
}
void ZorkUL::map()
{
    cout<<endl;
    cout<<"[!] = [A] = [B] = [C] = [D] = [E]      "<<endl;
    cout<<"       |           |           |       "<<endl;
    cout<<"      [F]   [G] = [H] = [I]   [J]      "<<endl;
    cout<<"       |     |     |     |     |       "<<endl;
    cout<<"      [K] = [L] = [M] = [N] = [O]      "<<endl;
    cout<<"       |     |     |     |     |       "<<endl;
    cout<<"      [P]   [Q] = [R] = [S]   [T]      "<<endl;
    cout<<"       |           |           |       "<<endl;
    cout<<"      [U] = [V] = [W] = [X] = [Y] = [Z]"<<endl;
}
