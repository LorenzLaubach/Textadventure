//
// Created by lorenz on 24.04.22.
//
#ifndef TEXTADVENTURE_ENEMIES_H
#define TEXTADVENTURE_ENEMIES_H
#include <string>
#include "common.h"


using namespace std;

class Enemy {
public:
    int m_damage;
    float m_life;
    string m_describtion;
    string m_name;
    string m_picture;
    //Position m_position;

    Enemy (const string& name, const int& damage, const float& life, const string& picture) :
    m_name(name),
    m_damage(damage),
    m_life(life),
    m_picture(picture)
    //m_position({0,0})
    {

    }

};

#endif //TEXTADVENTURE_ENEMIES_H
