#include <iostream>
#include <vector>
using namespace std;

// ========================
// 1️⃣ State Pattern
// ========================
class HeroState {
public:
    virtual void attack() = 0;
    virtual ~HeroState() {}
};

class NormalState : public HeroState {
public:
    void attack() override { cout << "Hero attacks normally!\n"; }
};

class PoweredUpState : public HeroState {
public:
    void attack() override { cout << "Hero attacks with super power!\n"; }
};

class InjuredState : public HeroState {
public:
    void attack() override { cout << "Hero attacks weakly...\n"; }
};

// ========================
// 2️⃣ Base Component for Composite Pattern
// ========================
class HeroComponent {
public:
    virtual void attack() = 0;
    virtual ~HeroComponent() {}
};

// ========================
// 3️⃣ Leaf Hero + State + Powers (Decorator)
// ========================
class Hero : public HeroComponent {
private:
    string name;
    HeroState* state;
    bool hasLaser = false;
    bool hasShield = false;
public:
    Hero(const string& n, HeroState* s) : name(n), state(s) {}

    void setState(HeroState* s) { state = s; }

    void addLaser() { hasLaser = true; }
    void addShield() { hasShield = true; }

    void attack() override {
        state->attack();
        if(hasLaser) cout << name << " fires laser!\n";
        if(hasShield) cout << name << " activates shield!\n";
    }

    string getName() const { return name; }
};

// ========================
// 4️⃣ Composite: Squad
// ========================
class Squad : public HeroComponent {
private:
    vector<HeroComponent*> members;
public:
    void add(HeroComponent* member) { members.push_back(member); }

    void attack() override {
        cout << "Squad attacks together:\n";
        for(auto m : members) m->attack();
    }
};

// ========================
// 5️⃣ Command Pattern: Buttons
// ========================
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

class AttackCommand : public Command {
private:
    HeroComponent* hero;
public:
    AttackCommand(HeroComponent* h) : hero(h) {}
    void execute() override { hero->attack(); }
};

// ========================
// 6️⃣ Facade: Mission preparation
// ========================
class SuperheroHQFacade {
private:
    Hero* hero;
public:
    SuperheroHQFacade(Hero* h) : hero(h) {}
    void prepareHero() {
        cout << "Facade: Preparing hero " << hero->getName() << "...\n";
        hero->addLaser();
        hero->addShield();
        cout << "Facade: Hero is ready!\n";
    }
};

// ========================
// 7️⃣ Main: Client code
// ========================
int main() {
    // States
    NormalState normal;
    PoweredUpState powered;
    InjuredState injured;

    // Individual heroes
    Hero* hero1 = new Hero("Captain C++", &normal);
    Hero* hero2 = new Hero("DebugGirl", &powered);
    Hero* hero3 = new Hero("MemoryMan", &injured);

    // Facade: prepare hero1
    SuperheroHQFacade facade(hero1);
    facade.prepareHero();

    // Squads
    Squad* alpha = new Squad();
    alpha->add(hero1);
    alpha->add(hero2);

    Squad* omega = new Squad();
    omega->add(alpha); // nested squad
    omega->add(hero3);

    // Commands
    AttackCommand attackHero1(hero1);
    AttackCommand attackHero2(hero2);
    AttackCommand attackAlpha(alpha);
    AttackCommand attackOmega(omega);

    cout << "\n--- Individual Hero Attack ---\n";
    attackHero1.execute();

    cout << "\n--- Alpha Squad Attack ---\n";
    attackAlpha.execute();

    cout << "\n--- Omega Squad Attack ---\n";
    attackOmega.execute();

    // Change hero state dynamically (State pattern)
    hero1->setState(&powered);
    cout << "\n--- Hero1 Powered Up Attack ---\n";
    attackHero1.execute();

    // Clean up
    delete hero1;
    delete hero2;
    delete hero3;
    delete alpha;
    delete omega;

    return 0;
}
