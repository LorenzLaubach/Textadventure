#ifndef TEXTADVENTURE_ENEMY_H
#define TEXTADVENTURE_ENEMY_H
#include <string>
#include "common/common.hpp"
#include "common/printing.hpp"
#include "objects.h"

using namespace std;

class Enemy : public spawnableObject {
public:
    int m_damage;
    float m_life;
    string m_describtion;
    //int m_earnedXP;

    Enemy(const string name, const string picture,
          spawnBoundaries spawnBound, const int damage, const float life)
    : spawnableObject(name, picture, spawnBound),
            m_damage(damage),
            m_life(life) {};

    ~Enemy() = default;
    virtual void defeated(const string& playerName) = 0;
};

#endif //TEXTADVENTURE_ENEMY_H
