#include <iostream>
#include <vector>
using namespace std;

// --------------------------------------------------
// Messy superhero code without design patterns
// Everything is in one place — hard to extend/maintain
// --------------------------------------------------

class Superhero {
public:
    string name;
    string state; // Normal, PoweredUp, Injured
    bool hasLaser;
    bool hasShield;

    Superhero(string n) : name(n), state("Normal"), hasLaser(false), hasShield(false) {}

    // Attack function handles everything
    void attack() {
        if(state == "Normal") {
            cout << name << " attacks normally!" << endl;
        } else if(state == "PoweredUp") {
            cout << name << " attacks with super power!" << endl;
        } else if(state == "Injured") {
            cout << name << " attacks weakly..." << endl;
        }

        if(hasLaser) cout << name << " fires laser blast!" << endl;
        if(hasShield) cout << name << " activates shield during attack!" << endl;
    }

    // Defend function with multiple responsibilities
    void defend() {
        if(state == "Normal") cout << name << " defends normally." << endl;
        else if(state == "PoweredUp") cout << name << " defends strongly!" << endl;
        else if(state == "Injured") cout << name << " barely defends..." << endl;

        if(hasShield) cout << name << " blocks all attacks with shield!" << endl;
    }

    void heal() {
        if(state == "Injured") {
            cout << name << " heals and becomes Normal." << endl;
            state = "Normal";
        } else {
            cout << name << " heals." << endl;
        }
    }
};

// --------------------------------------------------
// Messy squad system
// --------------------------------------------------
class Squad {
public:
    vector<Superhero*> members;

    void add(Superhero* hero) { members.push_back(hero); }

    void attackSquad() {
        cout << "Squad attacks together:" << endl;
        for(auto m : members) {
            m->attack();
        }
    }

    void defendSquad() {
        cout << "Squad defends together:" << endl;
        for(auto m : members) {
            m->defend();
        }
    }
};

// --------------------------------------------------
// Messy “button” system for invoking actions
// --------------------------------------------------
class Button {
public:
    string action; // "attack", "defend", "heal"
    Superhero* hero;

    Button(Superhero* h, string a) : hero(h), action(a) {}

    void press() {
        if(action == "attack") hero->attack();
        else if(action == "defend") hero->defend();
        else if(action == "heal") hero->heal();
        else cout << "Unknown action!" << endl;
    }
};

// --------------------------------------------------
// Main program
// --------------------------------------------------
int main() {
    // Create heroes
    Superhero* hero1 = new Superhero("Captain C++");
    Superhero* hero2 = new Superhero("DebugGirl");
    Superhero* hero3 = new Superhero("MemoryMan");

    // Equip powers
    hero1->hasLaser = true;
    hero2->hasShield = true;
    hero3->state = "PoweredUp";

    // Create messy squad
    Squad* squad1 = new Squad();
    squad1->add(hero1);
    squad1->add(hero2);

    Squad* squad2 = new Squad();
    squad2->add(squad1->members[0]); // messy nesting manually
    squad2->add(hero3);

    // Press buttons
    Button attackBtn(hero1, "attack");
    Button defendBtn(hero2, "defend");
    Button healBtn(hero3, "heal");

    cout << "\nIndividual attacks:\n";
    attackBtn.press();
    defendBtn.press();
    healBtn.press();

    cout << "\nSquad attacks:\n";
    squad1->attackSquad();

    cout << "\nBig squad attacks:\n";
    squad2->attackSquad();

    // Clean up
    delete hero1;
    delete hero2;
    delete hero3;
    delete squad1;
    delete squad2;

    return 0;
}
