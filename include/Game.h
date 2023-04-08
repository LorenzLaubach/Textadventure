//
// Created by Lorenz on 19.07.2022.
//
#ifndef TEXTADVENTURE_GAME_H
#define TEXTADVENTURE_GAME_H

#include "Player.h"
#include "map.h"
#include "objects.h"
#include "common/printing.hpp"
#include "ASCII/sword.h"
#include "ASCII/troll.h"

#include <iostream>
#include <random>
#include "common/random_generator.h"
#include "spawner.h"

class Game {
private:
    Map m_map;
    Player m_player;

public:
    Game(const int& x_mapSize, const int& y_mapSize);
    Spawner m_spawner;
    void play();

};
#endif //TEXTADVENTURE_GAME_H
