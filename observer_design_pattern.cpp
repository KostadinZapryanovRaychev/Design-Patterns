#include <iostream>
#include <vector>
using namespace std;

// Observer interface
class Animal {
public:
    virtual void reactToWeather(const string& weather) = 0;
    virtual ~Animal() {}
};

// Subject
class WeatherStation {
private:
    vector<Animal*> observers; // list of animals watching the weather
    string currentWeather;

public:
    void attach(Animal* animal) {
        observers.push_back(animal);
    }

    void detach(Animal* animal) {
        observers.erase(remove(observers.begin(), observers.end(), animal), observers.end());
    }

    void setWeather(const string& weather) {
        currentWeather = weather;
        notify();
    }

    string getWeather() const {
        return currentWeather;
    }

    void notify() {
        for (auto animal : observers) {
            animal->reactToWeather(currentWeather);
        }
    }
};

// Concrete Observers (Animals)
class Dog : public Animal {
public:
    void reactToWeather(const string& weather) override {
        if (weather == "Rainy") {
            cout << "Dog: Woof! Let's go inside, it's raining!" << endl;
        } else if (weather == "Sunny") {
            cout << "Dog: Woof! Time to play outside!" << endl;
        } else {
            cout << "Dog: Woof! Hmm, something is happening with the weather..." << endl;
        }
    }
};

class Cat : public Animal {
public:
    void reactToWeather(const string& weather) override {
        if (weather == "Rainy") {
            cout << "Cat: Meow! I'm hiding under the couch, too wet outside." << endl;
        } else if (weather == "Sunny") {
            cout << "Cat: Meow! Perfect nap time in the sun." << endl;
        } else {
            cout << "Cat: Meow! Strange weather today..." << endl;
        }
    }
};

class Bird : public Animal {
public:
    void reactToWeather(const string& weather) override {
        if (weather == "Rainy") {
            cout << "Bird: Chirp! Staying in the nest, rain is falling." << endl;
        } else if (weather == "Sunny") {
            cout << "Bird: Chirp! Time to fly and sing in the sunshine!" << endl;
        } else {
            cout << "Bird: Chirp! Wonder what the weather will do..." << endl;
        }
    }
};

// Main program
int main() {
    WeatherStation station;

    Dog dog;
    Cat cat;
    Bird bird;

    // Attach animals to the weather station
    station.attach(&dog);
    station.attach(&cat);
    station.attach(&bird);

    cout << "Weather changes to Sunny:\n";
    station.setWeather("Sunny"); // All animals react

    cout << "\nWeather changes to Rainy:\n";
    station.setWeather("Rainy"); // All animals react

    cout << "\nCat goes inside and stops observing...\n";
    station.detach(&cat);

    cout << "\nWeather changes to Sunny again:\n";
    station.setWeather("Sunny"); // Only Dog and Bird react

    return 0;
}
