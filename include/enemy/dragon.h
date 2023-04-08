#pragma once
#include "Enemy.h"
#include <ASCII/dragon_ascii.h>

class Dragon : public Enemy {
public:
    Dragon() : Enemy("Detlef der Drache",
                     dragonASCII,
                     spawnBoundaries{2,2,2,2},
                     50,
                     200)
    {}

    void defeated(const std::string& playerName) override {
        print("You are incredible " + playerName + " never have someone defeated Detlef den Drachen");
    }

    void inspectByPlayer() override {
        print("Holy Maccaroni there is " + m_name + " and chewing on some dirty dumplings");
        cout << m_picture << endl;
    }
};