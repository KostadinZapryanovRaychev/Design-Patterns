#include <iostream>
using namespace std;

// -----------------------------
// 1️⃣ State Interface
// Defines a common interface for all states
// -----------------------------
class HeroState {
public:
    virtual void attack() = 0; // each state defines its own attack behavior
    virtual ~HeroState() {}
};

// -----------------------------
// 2️⃣ Concrete States
// Each state implements the attack behavior differently
// -----------------------------
class NormalState : public HeroState {
public:
    void attack() override {
        cout << "Hero attacks normally!" << endl;
    }
};

class PoweredUpState : public HeroState {
public:
    void attack() override {
        cout << "Hero attacks with super power!" << endl;
    }
};

class InjuredState : public HeroState {
public:
    void attack() override {
        cout << "Hero attacks weakly..." << endl;
    }
};

// -----------------------------
// 3️⃣ Context Class (Hero)
// Maintains a reference to the current state
// -----------------------------
class Hero {
private:
    HeroState* state; // current state
public:
    Hero(HeroState* initial) : state(initial) {}

    // Change the internal state dynamically
    void setState(HeroState* newState) {
        state = newState;
    }

    // Delegate behavior to current state
    void attack() {
        state->attack();
    }
};

// -----------------------------
// 4️⃣ Client Code
// Demonstrates changing the hero's behavior dynamically
// -----------------------------
int main() {
    // Create concrete states
    NormalState normal;
    PoweredUpState powered;
    InjuredState injured;

    // Create hero starting in normal state
    Hero hero(&normal);

    cout << "Hero in normal state:\n";
    hero.attack(); // Normal attack

    cout << "\nHero powered up:\n";
    hero.setState(&powered);
    hero.attack(); // Super attack

    cout << "\nHero injured:\n";
    hero.setState(&injured);
    hero.attack(); // Weak attack

    return 0;
}


// The State pattern encapsulates state-specific
// behavior in separate classes and lets the object change its behavior dynamically by switching states.