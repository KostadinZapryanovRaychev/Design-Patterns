// Command encapsulates a request as an object, allowing you to parameterize clients, queue requests, or support undo/redo.
//
// Think of it like:
//
// You have buttons in a superhero HQ
//
// Each button triggers a different action (attack, defend, heal)
//
// Button doesn’t need to know how the action works
//
// Command object holds the action and executes it


#include <iostream>
#include <vector>
using namespace std;

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

class Superhero {
private:
    string name;
public:
    Superhero(const string& n) : name(n) {}

    void attack() {
        cout << name << " attacks the enemy!" << endl;
    }

    void defend() {
        cout << name << " defends from the attack!" << endl;
    }

    void heal() {
        cout << name << " heals and recovers strength!" << endl;
    }
};

class AttackCommand : public Command {
private:
    Superhero* hero;
public:
    AttackCommand(Superhero* h) : hero(h) {}
    void execute() override {
        hero->attack();
    }
};

class DefendCommand : public Command {
private:
    Superhero* hero;
public:
    DefendCommand(Superhero* h) : hero(h) {}
    void execute() override {
        hero->defend();
    }
};

class HealCommand : public Command {
private:
    Superhero* hero;
public:
    HealCommand(Superhero* h) : hero(h) {}
    void execute() override {
        hero->heal();
    }
};

class Button {
private:
    Command* command;
public:
    void setCommand(Command* cmd) {
        command = cmd;
    }

    void press() {
        if(command)
            command->execute(); // execute command when button is pressed
    }
};

int main() {
    Superhero hero("Captain C++");

    // Create commands
    AttackCommand attack(&hero);
    DefendCommand defend(&hero);
    HealCommand heal(&hero);

    // Buttons (Invoker)
    Button attackButton;
    Button defendButton;
    Button healButton;
    attackButton.setCommand(&attack);
    defendButton.setCommand(&defend);
    healButton.setCommand(&heal);

    cout << "Hero presses attack button:\n";
    attackButton.press();

    cout << "\nHero presses defend button:\n";
    defendButton.press();

    cout << "\nHero presses heal button:\n";
    healButton.press();

    return 0;
}
