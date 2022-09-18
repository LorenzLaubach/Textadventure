//
// Created by lorenz on 24.04.22.
//
#ifndef TEXTADVENTURE_ENEMY_H
#define TEXTADVENTURE_ENEMY_H
#include <string>
#include "common.hpp"

using namespace std;

class Enemy {
public:
    int m_damage;
    float m_life;
    string m_describtion;
    string m_name;
    string m_picture;
    spawnBoundaries m_spawnBound;
    //Position m_position;


    Enemy (const string& name, const int& damage, const float& life,
           const string& picture, const spawnBoundaries& spawn) :
    m_name(name),
    m_damage(damage),
    m_life(life),
    m_picture(picture),
    m_spawnBound(spawn)
    {}
};

#endif //TEXTADVENTURE_ENEMY_H
