#ifndef MAP_H
#define MAP_H
#include <vector>
#include <map>
#include "enemies.h"
#include "printing.h"
#include "common.h"


class Map {
private:
    mapSize m_mapFields;

public:
    map<Position, Enemy> m_enemiesPosition;

    Map(int x_size, int y_size) {
        // Initialize the size of the map
        m_mapFields.m_xSize = x_size;
        m_mapFields.m_ySize = y_size;

    }
    Position m_playerPosition = Position {0,0};

    mapSize getMapSize() {
        return m_mapFields;
    }

    void spawnEnemies(std::vector<Enemy>& enemies) {
        for (Enemy& enemy : enemies) {
            if (enemy.m_name == "Troll") {
                while(enemy.m_position.x == 0 && enemy.m_position.y == 0) {
                    enemy.m_position.x = randNumbers(0, 1);
                    enemy.m_position.y = randNumbers(0, 1);
                }
                this->m_enemiesPosition.insert(pair<Position, Enemy>(enemy.m_position, enemy));
            }
        }
    }
};
#endif