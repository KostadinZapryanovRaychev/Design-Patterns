//
// Created by MacBook Pro on 22.01.26.
//

#include <iostream>
using namespace std;

#include <iostream>;
using namespace std;

class Logger {

    // Constructor is private
private:
    Logger() {
        cout << "Logger created\n";
    }

    // object from the type of class initially it is nullptr;
    static Logger* instance;

    // pointer to the constructor is public and it calls the constructor in itself;
public:
    static Logger* create() {
        // if not still created it creates a new one.

        if (instance == nullptr) {
            //*
            instance = new Logger();
        }
        // if created return the old one;
        // the ----> *
        return instance;
    }
};

int main() {
    Logger* logger = Logger::create();
    return 0;
}
