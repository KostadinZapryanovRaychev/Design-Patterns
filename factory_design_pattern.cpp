// creational design patterns
// behavioural design patterns
// structural design patterns

// they are language indipendant


// FDP ----> Creational design pattern

#include <iostream>
using namespace std;

class Car {
public:
    virtual void drive() = 0;
    virtual ~Car() {}
};

class BMW : public Car {
    public:
        void drive() override {
        cout << "Driving BMW\n";
    }
};

class Audi : public Car {
public:
    void drive() override {
        cout << "Driving Audi\n";
    }
};

class VolksWagen :public Car {
    public:
      void drive() override {
          cout << "Driving VolksWagen\n";
      }

};

class Citroen :public Car {
    public:
      void drive() override {
          cout << "Driving Citroen\n";
      }
};

class CarFactory {
public:
    static Car* create(const string& name) {
        if (name == "BMW")
            return new BMW();
        else if (name == "Audi")
            return new Audi();
        else if (name == "VolksWagen")
            return new VolksWagen();
        else if (name == "Citroen")
            return new Citroen();
        else
            return nullptr;
    }
};


int main() {
    // !!! static Car* create(const string& name);
    // ❌ Without static, you’d need:

    // CarFactory factory;
    // factory.create("BMW");

    Car* car1 = CarFactory::create("BMW");
    Car* car2 = CarFactory::create("Audi");
    Car* car3 = CarFactory::create("VolksWagen");
    Car* car4 = CarFactory::create("Citroen");

    car1->drive();
    car2->drive();
    car3->drive();
    car4->drive();

    delete car1;
    delete car2;
    delete car3;
    delete car4;

    return 0;
}