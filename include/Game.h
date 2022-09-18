//
// Created by Lorenz on 19.07.2022.
//
#ifndef TEXTADVENTURE_GAME_H
#define TEXTADVENTURE_GAME_H

#include "Player.h"
#include "map.h"
#include "objects.h"
#include "printing.hpp"
#include "Enemy.h"
#include "ASCII/sword.h"
#include "ASCII/troll.h"

class Game {
private:
    Map m_map;
    Player m_player;
public:
    bool debug;

    // Constructor
    Game(const int& x_mapSize, const int& y_mapSize);

    void play();

};
#endif //TEXTADVENTURE_GAME_H
