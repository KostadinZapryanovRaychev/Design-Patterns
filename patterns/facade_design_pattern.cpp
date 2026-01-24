// Facade Design Pattern
// Core Idea (Simple)
// Facade provides a simplified interface to a complex system.
// Think of it like:
// You want to turn on a computer
// Internally: CPU, Memory, Hard Disk, BIOS, Fans…
// You don’t want to deal with all that
// Facade = startComputer() → hides complexity


// Fun example: Superhero Game HQ
//
// Imagine a Superhero HQ with multiple departments:
//
// PowerSupply
//
// WeaponSystem
//
// TrainingRoom
//
// You want your hero to prepare for mission with one simple call.


#include <iostream>
using namespace std;

// Subsystem 1
class PowerSupply {
public:
    void turnOn() { cout << "PowerSupply: powering up!\n"; }
};

// Subsystem 2
class WeaponSystem {
public:
    void armWeapons() { cout << "WeaponSystem: weapons armed!\n"; }
};

// Subsystem 3
class TrainingRoom {
public:
    void startTraining() { cout << "TrainingRoom: training initiated!\n"; }
};

class SuperheroHQFacade {
private:
    PowerSupply* power;
    WeaponSystem* weapons;
    TrainingRoom* training;

public:
    SuperheroHQFacade(PowerSupply* p, WeaponSystem* w, TrainingRoom* t)
        : power(p), weapons(w), training(t) {}

    // : power(p), weapons(w), training(t)
    // The colon : introduces the member initializer list
    // This is a special C++ syntax to initialize member variables before the constructor body runs
    // It means:
    // this->power = p;
    // this->weapons = w;
    // this->training = t;

    void prepareHero() {
        cout << "Facade: Preparing hero for mission...\n";
        power->turnOn();
        weapons->armWeapons();
        training->startTraining();
        cout << "Facade: Hero is ready!\n";
    }
};


int main() {
    PowerSupply power;
    WeaponSystem weapons;
    TrainingRoom training;

    SuperheroHQFacade facade(&power, &weapons, &training);

    facade.prepareHero();

    return 0;
}
