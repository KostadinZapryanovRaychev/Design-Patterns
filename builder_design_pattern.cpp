#include <iostream>
#include <string>
using namespace std;

class Gadget {
public:
    string laser;
    string shield;
    string jetpack;

    void show() const {
        cout << "Gadget features:\n";
        cout << "Laser: " << (laser.empty() ? "None" : laser) << endl;
        cout << "Shield: " << (shield.empty() ? "None" : shield) << endl;
        cout << "Jetpack: " << (jetpack.empty() ? "None" : jetpack) << endl;
    }
};

// Abstract class ---> at least one pure virtual function in it (= 0)
class GadgetBuilder {
public:
    virtual void buildLaser() = 0;
    virtual void buildShield() = 0;
    virtual void buildJetpack() = 0;
    virtual Gadget* getGadget() = 0;
    virtual ~GadgetBuilder() {}
};

class BasicGadgetBuilder : public GadgetBuilder {
private:
    Gadget* gadget;
public:
    BasicGadgetBuilder() { gadget = new Gadget(); }

    void buildLaser() override { gadget->laser = "Small laser"; }
    void buildShield() override { gadget->shield = "Basic shield"; }
    void buildJetpack() override { gadget->jetpack = ""; } // no jetpack

    Gadget* getGadget() override { return gadget; }
};

class AdvancedGadgetBuilder : public GadgetBuilder {
private:
    Gadget* gadget;
public:
    AdvancedGadgetBuilder() { gadget = new Gadget(); }

    void buildLaser() override { gadget->laser = "Powerful laser"; }
    void buildShield() override { gadget->shield = "Energy shield"; }
    void buildJetpack() override { gadget->jetpack = "Rocket jetpack"; }

    Gadget* getGadget() override { return gadget; }
};


class GadgetDirector {
private:
    GadgetBuilder* builder;
public:
    void setBuilder(GadgetBuilder* b) { builder = b; }

    Gadget* buildGadget() {
        builder->buildLaser();
        builder->buildShield();
        builder->buildJetpack();
        return builder->getGadget();
    }
};


int main() {
    GadgetDirector director;

    // Build a basic gadget
    BasicGadgetBuilder basicBuilder;
    director.setBuilder(&basicBuilder);
    Gadget* basicGadget = director.buildGadget();

    cout << "Basic Gadget:\n";
    basicGadget->show();
    cout << endl;

    AdvancedGadgetBuilder advBuilder;
    director.setBuilder(&advBuilder);
    Gadget* advancedGadget = director.buildGadget();

    cout << "Advanced Gadget:\n";
    advancedGadget->show();
    cout << endl;

    delete basicGadget;
    delete advancedGadget;

    return 0;
}




