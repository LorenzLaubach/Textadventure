#pragma once
#include "Enemy.h"
#include "ASCII/bug_ascii.h"

class Bug : public Enemy {
public:
    Bug() : Enemy("bug",
                  bugASCII,
                  spawnBoundaries{0,0,1,1},
                  2,
                  20)
    {}

    void inspectByPlayer() override {
        print("Oh no this Game is full of Bugs, careful ");
        cout << m_picture << endl;
    }

    void defeated(const std::string& playerName) override {
        print("Grr Damn you " + playerName + ", feel good for now because of that win, but you're still "
                                             "wasting your time! Hehehe");
    }

};