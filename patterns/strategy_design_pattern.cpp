// Strategy lets you define a family of algorithms, encapsulate each one, and make them interchangeable.
//
// Think of it like:
//
// Superhero combat moves
//
// Different strategies: Punch, Kick, LaserBlast
//
// Hero can swap strategies at runtime
//
// Client code doesn’t need to know the exact algorithm

#include <iostream>
using namespace std;

// Base Strategy
class AttackStrategy {
public:
    virtual void attack() = 0; // all strategies implement this
    virtual ~AttackStrategy() {}
};

class Punch : public AttackStrategy {
public:
    void attack() override {
        cout << "Hero attacks with a powerful punch!" << endl;
    }
};

class Kick : public AttackStrategy {
public:
    void attack() override {
        cout << "Hero attacks with a flying kick!" << endl;
    }
};

class LaserBlast : public AttackStrategy {
public:
    void attack() override {
        cout << "Hero attacks with laser blast!" << endl;
    }
};

class Hero {
private:
    AttackStrategy* strategy; // current attack strategy
public:
    Hero(AttackStrategy* initial) : strategy(initial) {}

    void setStrategy(AttackStrategy* newStrategy) {
        strategy = newStrategy; // swap strategy at runtime
    }

    void attack() {
        strategy->attack(); // delegate to current strategy
    }
};

int main() {
    // Create strategies
    Punch punch;
    Kick kick;
    LaserBlast laser;

    // Hero starts with punch strategy
    Hero hero(&punch);

    cout << "Hero uses punch:\n";
    hero.attack();

    cout << "\nHero switches to kick:\n";
    hero.setStrategy(&kick);
    hero.attack();

    cout << "\nHero switches to laser blast:\n";
    hero.setStrategy(&laser);
    hero.attack();

    return 0;
}


// Encapsulates algorithms → no messy if/else in Hero class
//
// Swap behavior at runtime without changing Hero class
//
// Extensible → add new strategies without modifying existing code
//
// Real-world examples
//
// Payment systems: CreditCardPayment, PayPalPayment, CryptoPayment
//
// Sorting algorithms: QuickSort, MergeSort, BubbleSort
//
// Game AI: different attack or movement strategies