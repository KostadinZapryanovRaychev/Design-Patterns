
// Singleton ensures that a class has ONLY ONE instance and provides a global access point to it.


//Singleton is used for:

// Logger

// Configuration manager

// Database connection pool

// Cache

// Thread pool

#include <iostream>
using namespace std;

class Logger {
    // verry important private constructor
private:
    Logger() {
        cout << "Logger created\n";
    }

    static Logger* instance;

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void log(const string& msg) {
        cout << "Log: " << msg << endl;
    }
};

Logger* Logger::instance = nullptr;

int main() {
    Logger* l1 = Logger::getInstance();
    Logger* l2 = Logger::getInstance();

    l1->log("Hello");
    l2->log("World");

    cout << (l1 == l2) << endl; // 1 (true)
}
