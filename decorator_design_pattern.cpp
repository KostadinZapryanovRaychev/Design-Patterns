// Decorator Design Pattern
// Core Idea (Simple)
// Decorator lets you add new behavior to an object dynamically, without modifying its class.
// Think of it like:
// You have a plain ice cream
// You want to add toppings (chocolate, nuts, syrup)
// Instead of changing the original ice cream class, you wrap it in decorators

#include <iostream>
#include <string>
using namespace std;

// Base interface
class Superhero {
public:
    virtual void attack() = 0;
    virtual ~Superhero() {}
};

class BasicHero : public Superhero {
private:
    string name;
public:
    BasicHero(const string& n) : name(n) {}

    void attack() override {
        cout << name << " attacks with fists!" << endl;
    }
};


// Stores a pointer to the wrapped object
// Delegates calls to it
// This is the key of dynamic behavior addition
class HeroDecorator : public Superhero {
protected:
    Superhero* hero; // wrap a superhero
public:
    HeroDecorator(Superhero* h) : hero(h) {}
    virtual void attack() override {
        hero->attack(); // delegate to wrapped hero
    }
};

class LaserEyes : public HeroDecorator {
public:
    LaserEyes(Superhero* h) : HeroDecorator(h) {}

    void attack() override {
        hero->attack(); // base attack
        cout << " + Laser eyes blast!" << endl; // extra behavior
    }
};

class Shield : public HeroDecorator {
public:
    Shield(Superhero* h) : HeroDecorator(h) {}

    void attack() override {
        hero->attack(); // base attack
        cout << " + Protective shield activated!" << endl;
    }
};


int main() {
    // Base hero
    Superhero* hero = new BasicHero("Captain C++");

    cout << "Base Hero:\n";
    hero->attack();
    cout << "\n";

    // Add Laser Eyes
    Superhero* laserHero = new LaserEyes(hero);
    cout << "Hero with Laser Eyes:\n";
    laserHero->attack();
    cout << "\n";

    // Add Shield on top of Laser Eyes
    Superhero* ultimateHero = new Shield(laserHero);
    cout << "Ultimate Hero:\n";
    ultimateHero->attack();
    cout << "\n";

    // Clean up
    delete hero;
    delete laserHero;
    delete ultimateHero;
    return 0;
}

// Add behavior dynamically
// Combine multiple decorators
// Base class stays unchanged
// Supports open/closed principle
