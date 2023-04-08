#pragma once

#include "weapon.h"
#include "ASCII/sword.h"
#include <string>
#include "common/printing.hpp"

using namespace std;

class Sword : public Weapon {
public:
    Sword()
    : Weapon("Sword", swordASCII, {0,0,1,1}, 15){}
    ~Sword() {};

    void inspectByPlayer() override {
        print("Nice there is a " + m_name + " laying around here"
        );
        cout << m_picture << endl;
        print("Picking up " + m_name + "...");
    }
};