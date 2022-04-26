#ifndef MAP_H
#define MAP_H
#include <vector>
#include <map>
#include "enemies.h"
#include "printing.h"

struct Position {
public:
    int x;
    int y;
};

bool operator<(const Position& l, const Position& r) {
    return (l.x<r.x || (l.x==r.x && l.y<r.y));
}

struct mapSize {
    int m_xSize;
    int m_ySize;
};

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
            Position enemyPosition = Position{randNumbers(0,1), randNumbers(0,1)};
            this->m_enemiesPosition.insert(pair<Position, Enemy>(enemyPosition, enemy));
        }
    }
};
#endif