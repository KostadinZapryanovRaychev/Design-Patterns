//
// Created by MacBook Pro on 22.01.26.
//
// A factory pattern for factory patterns

#include <iostream>
using namespace std;

class Engine {
public:
    virtual void start() = 0;
    virtual ~Engine() {}
};

class Tyre {
public:
    virtual void rotate() = 0;
    virtual ~Tyre() {}
};

class BMWEngine : public Engine {
public:
    void start() override {
        cout << "BMW Engine started\n";
    }
};

class BMWTyre : public Tyre {
public:
    void rotate() override {
        cout << "BMW Tyre rotating\n";
    }
};

class AudiEngine : public Engine {
public:
    void start() override {
        cout << "Audi Engine started\n";
    }
};

class AudiTyre : public Tyre {
public:
    void rotate() override {
        cout << "Audi Tyre rotating\n";
    }
};

class CarFactory {
public:
    virtual Engine* createEngine() = 0;
    virtual Tyre* createTyre() = 0;
    virtual ~CarFactory() {}
};

class BMWFactory : public CarFactory {
public:
    Engine* createEngine() override {
        return new BMWEngine();
    }

    Tyre* createTyre() override {
        return new BMWTyre();
    }
};

class AudiFactory : public CarFactory {
public:
    Engine* createEngine() override {
        return new AudiEngine();
    }

    Tyre* createTyre() override {
        return new AudiTyre();
    }
};



int main() {
    CarFactory* factory1 = new BMWFactory();
    Engine* engine1 = factory1->createEngine();
    Tyre* tyre1 = factory1->createTyre();

    engine1->start();
    tyre1->rotate();

    cout << "-----------------\n";

    CarFactory* factory2 = new AudiFactory();
    Engine* engine2 = factory2->createEngine();
    Tyre* tyre2 = factory2->createTyre();

    engine2->start();
    tyre2->rotate();

    delete engine1;
    delete tyre1;
    delete factory1;

    delete engine2;
    delete tyre2;
    delete factory2;

    return 0;
}
