// Core Idea (Simple)
//
// Composite lets you treat individual objects and compositions of objects uniformly.
//
// Think of it like:
//
// Superheroes and squads
//
// Some heroes fight alone (leaf nodes)
//
// Some squads contain multiple heroes (composite nodes)
//
// You can call attack() on a hero or a squad — same interface

#include <iostream>
#include <vector>
using namespace std;

// Base Component
class HeroComponent {
public:
    virtual void attack() = 0; // common operation
    virtual ~HeroComponent() {}
};

class Hero : public HeroComponent {
private:
    string name;
public:
    Hero(const string& n) : name(n) {}

    void attack() override {
        cout << name << " attacks alone!" << endl;
    }
};


class Squad : public HeroComponent {
private:
    vector<HeroComponent*> members; // can contain heroes or other squads
public:
    void add(HeroComponent* member) {
        members.push_back(member);
    }

    void attack() override {
        cout << "Squad attacks together:" << endl;
        for (auto member : members) {
            member->attack(); // delegate attack to all members
        }
    }
};

int main() {
    Hero* hero1 = new Hero("Captain C++");
    Hero* hero2 = new Hero("DebugGirl");
    Hero* hero3 = new Hero("MemoryMan");

    Squad* alphaSquad = new Squad();
    alphaSquad->add(hero1);
    alphaSquad->add(hero2);

    // Create a big squad containing alpha squad + another hero
    Squad* omegaSquad = new Squad();
    omegaSquad->add(alphaSquad); // nested squad
    omegaSquad->add(hero3);

    cout << "Single hero attack:\n";
    hero1->attack();
    cout << "\nAlpha squad attack:\n";
    alphaSquad->attack();
    cout << "\nOmega squad attack:\n";
    omegaSquad->attack();

    // Clean up
    delete hero1;
    delete hero2;
    delete hero3;
    delete alphaSquad;
    delete omegaSquad;

    return 0;
}

