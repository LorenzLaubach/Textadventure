//
// Created by lorenz on 24.04.22.
//
#ifndef TEXTADVENTURE_ENEMIES_H
#define TEXTADVENTURE_ENEMIES_H
#include <string>
#include "../ASCII/troll.h"

using namespace std;

class Enemy {
public:
    int m_damage;
    float m_life;
    string m_describtion;
    string m_name;
    string m_picture = trollASCII;

    Enemy(const string& name, const int& damage, const float& life) {
        m_name = name;
        m_damage = damage;
        m_life = life;
    }

};

#endif //TEXTADVENTURE_ENEMIES_H
