//
// Created by Lorenz on 28.07.2022.
//
#include <Game.h>

Game::Game(const int& x_mapSize,const int& y_mapSize):
        m_map(x_mapSize, y_mapSize),
        m_player(m_map, Weapon("Axe", 1, 5, "",
                               {0,0,0,0})) {

#ifdef DEBUG
    print("Now running in Debugging Mode");
    debug = true;
#endif
    // Enemy Spawner
    static Enemy troll = Enemy("Troll", 10, 70, trollASCII,
                        spawnBoundaries({0,0,1,1}));
    m_map.spawnEnemies(troll);

    static Weapon sword = Weapon("Sword", 1, 15, swordASCII,
                           spawnBoundaries({0,0,1,1}));
    m_map.spawnWeapons(sword);
}

void Game::play() {
    int round = 1;
    while(m_player.isPlaying) {
        changeColour(2);
        cout << "--------------------------\nRound" + to_string(round++) << endl;
        changeColour(15);
        m_player.chooseAction();
    }
}
