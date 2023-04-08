//
// Created by Lorenz on 28.07.2022.
//
#include <Game.h>
#include "common/random_generator.h"


Game::Game(const int& x_mapSize,const int& y_mapSize):
        m_map(x_mapSize, y_mapSize),
        m_player(m_map),
        m_spawner(m_map)
{
}

void Game::play() {
    int round = 1;
    while(m_player.isPlaying) {
        changeColour(2);
        cout << "-----------------------------------------------------\nRound" + to_string(round++) << endl;
        changeColour(15);
        m_player.chooseAction();
    }
}
