#pragma once

#include "weapon.h"
#include <string>
#include "common/printing.hpp"

using namespace std;

class Axe : public Weapon {
public:
//    static string m_name = "Axe";
//    string m_picture = "";
//    spawnBoundaries m_spawnBoundaries = spawnBoundaries{999,999,1000,1000};
//    int m_damage = 5;

    Axe()
    : Weapon("Axe", "", spawnBoundaries(999,999,1000,1000), 5) {};
    ~Axe() {};

    void inspectByPlayer() override {
        print("Nice there is a " + m_name + " laying around here"
        );
        cout << m_picture << endl;
        print("Picking up " + m_name + "...");
    }
};


