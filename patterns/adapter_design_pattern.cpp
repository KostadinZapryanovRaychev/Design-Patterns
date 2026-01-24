//The core idea (very simple)
// Adapter lets two incompatible interfaces work together.
// Think of it like:
// Phone charger adapter
// The socket and charger don’t match
//Adapter converts one interface to another

#include <iostream>
using namespace std;

// Target interface
class Weapon {
public:
    virtual void attack() = 0;
    virtual ~Weapon() {}
};

// Adaptee (old / incompatible class)
class OldLaserGun {
public:
    void shootLaser() {
        cout << "OldLaserGun: Pew pew laser!" << endl;
    }
};

// Adapter
class LaserGunAdapter : public Weapon {
private:
    OldLaserGun* laserGun;

public:
    LaserGunAdapter(OldLaserGun* gun) : laserGun(gun) {}

    void attack() override {
        // Translate attack() → shootLaser()
        laserGun->shootLaser();
    }
};

// Client function (MUST be outside main)
void fight(Weapon* weapon) {
    weapon->attack();
}

int main() {
    OldLaserGun oldGun;
    Weapon* adaptedWeapon = new LaserGunAdapter(&oldGun);
    fight(adaptedWeapon);
    delete adaptedWeapon;
    return 0;
}
