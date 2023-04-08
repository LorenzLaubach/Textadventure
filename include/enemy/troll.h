#pragma once

#include "Enemy.h"
#include <ASCII/troll.h>

//namespace troll {
//    const string name = "Uzgugh der Troll";
//    const string pic = trollASCII;
//    spawnBoundaries spawnBounds = spawnBoundaries{1,1,2,2};
//    const int damage = 10;
//    const float life = 70;
//}

class Troll : public Enemy {
public:
    Troll() : Enemy("Uzgugh der Troll",
                    trollASCII,
                    {1,1,2,2},
                    10,
                    70)
    {}

    void inspectByPlayer() override {
        print("Yikes there is " + m_name + " in front of you");
        cout << m_picture << endl;
    }

    void defeated(const std::string& playerName) override {
        print("Grr Damn you " + playerName + ", feel good for now because of that win, but you're still "
                                             "wasting your time! Hehehe");
    }

};
