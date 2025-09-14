#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Ghost {
protected:
    string workerName;
    int scareLevel;
public:
    Ghost(string w) : workerName(w), scareLevel(rand() % 9 + 1) {}
    virtual void haunt() 
    {
        cout << workerName << " haunts with scare level " << scareLevel << endl;
    }
    friend ostream& operator<<(ostream& os, Ghost& ghost) 
    {
        os << "Ghost played by: " << ghost.workerName << ", Scare Level: " << ghost.scareLevel;
        return os;
    }
    int getScareLevel() 
    { 
        return scareLevel; 
    }
};

class Poltergeist : public Ghost {
public:
    Poltergeist(string w) : Ghost(w) {}
    void haunt() override 
    {
        cout << workerName << "poltergeist moves" << endl;
    }
};

class Banshee : public Ghost {
public:
    Banshee(string w) : Ghost(w) {}
    void haunt() override 
    {
        cout << workerName << "banshee screams" << endl;
    }
};

class ShadowGhost : public Ghost {
public:
    ShadowGhost(string w) : Ghost(w) {}
    void haunt() override 
    {
        cout << workerName << "shadowghost whispers" << endl;
    }
};

class Visitor {
    string name;
    int braveryLevel;
public:
    Visitor(string n, int b) : name(n), braveryLevel(b) {}
    void react(int scare) 
    {
        if (scare < braveryLevel - 3) 
        {
            cout << name << " laughs at the ghost" << endl;
        }
        else if (scare > braveryLevel + 3) {
            cout << name << " screams and runs awayy" << endl;
        }
        else {
            cout << name << "shaky voice" << endl;
        }
    }
};

class HauntedHouse {
    string houseName;
    vector<Ghost*> ghosts;
public:
    HauntedHouse(string n) : houseName(n) {}
    void addGhost(Ghost* ghost) 
    { 
        ghosts.push_back(ghost); 
    }
    void hostVisitors(vector<Visitor>& visitors) 
    {
        cout << "\nVisitors enter " << houseName << endl;
        for (auto& ghost : ghosts) 
        {
            ghost->haunt();
        }
        for (auto& visitor : visitors) 
        {
            visitor.react(ghosts[rand() % ghosts.size() + 0]->getScareLevel());
        }
    }
};

void visit(vector<Visitor> &visitors, HauntedHouse& house) 
{
    house.hostVisitors(visitors);
}

int main() {
        
    HauntedHouse house1("Mansion");
    house1.addGhost(new Poltergeist("John"));
    house1.addGhost(new Banshee("Alice"));
    house1.addGhost(new ShadowGhost("Eve"));

    HauntedHouse house2("Dark Forest Cabin");
    house2.addGhost(new ShadowGhost("Mike"));
    house2.addGhost(new Poltergeist("Sarah"));

    vector<Visitor> visitors = {
        Visitor("Tom", 2),
        Visitor("Jane", 6),
        Visitor("Mark", 9)
    };
    
    visit(visitors, house1);
    visit(visitors, house2);
    
}
