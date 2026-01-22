//The Prototype pattern allows you to create new objects by cloning an
//existing object (the prototype) instead of creating them from scratch.
// Created by MacBook Pro on 22.01.26.
//Key idea:

//You have an object with some state

//You clone it to make new objects

// Useful when creating objects is expensive or you want to preserve state

//Use cases:

// Game development (cloning characters)

// Document editors (copy/paste objects)

//Config templates

// Example bullet ----- going to some direction

#include <iostream>
#include <string>
using namespace std;

// Prototype interface
class SuperheroPrototype {
public:
    virtual SuperheroPrototype* clone() const = 0; // clone itself
    virtual void showPower() const = 0;            // demonstrate hero powers
    virtual ~SuperheroPrototype() {}
};

// Concrete Superhero: Flying Hero
class FlyingHero : public SuperheroPrototype {
private:
    string name;
public:
    FlyingHero(const string& n) : name(n) {}

    SuperheroPrototype* clone() const override {
        return new FlyingHero(*this); // copy constructor
    }

    void showPower() const override {
        cout << "FlyingHero " << name << " soars through the sky!" << endl;
    }

    void setName(const string& n) {
        name = n;
    }
};

// Concrete Superhero: Strong Hero
class StrongHero : public SuperheroPrototype {
private:
    string name;
public:
    StrongHero(const string& n) : name(n) {}

    SuperheroPrototype* clone() const override {
        return new StrongHero(*this);
    }

    void showPower() const override {
        cout << "StrongHero " << name << " lifts huge objects with ease!" << endl;
    }

    void setName(const string& n) {
        name = n;
    }
};

int main() {
    // Original superheroes (prototypes)
    FlyingHero* originalFlyer = new FlyingHero("SkyMaster");
    StrongHero* originalStrong = new StrongHero("MegaLift");

    cout << "Original heroes:\n";
    originalFlyer->showPower();
    originalStrong->showPower();

    cout << "\nCloning superheroes for the game...\n";

    // Clone superheroes
    SuperheroPrototype* flyerClone1 = originalFlyer->clone();
    SuperheroPrototype* flyerClone2 = originalFlyer->clone();
    SuperheroPrototype* strongClone1 = originalStrong->clone();

    // Give new names to clones
    dynamic_cast<FlyingHero*>(flyerClone1)->setName("WindRider");
    dynamic_cast<FlyingHero*>(flyerClone2)->setName("CloudSurfer");
    dynamic_cast<StrongHero*>(strongClone1)->setName("PowerSmash");

    // Show powers of cloned superheroes
    cout << "\nCloned heroes:\n";
    flyerClone1->showPower();
    flyerClone2->showPower();
    strongClone1->showPower();

    // Clean up
    delete originalFlyer;
    delete originalStrong;
    delete flyerClone1;
    delete flyerClone2;
    delete strongClone1;

    return 0;
}

