#ifndef MAP_H
#define MAP_H
#include <vector>
#include <map>
#include "Enemy.h"
#include "printing.hpp"
#include "common.hpp"
#include "objects.h"


struct Field {
    bool has_enemy = false;
    Enemy* p_enemy = nullptr;
    bool has_item = false;
    Weapon* p_object = nullptr;
};

class Map {
private:
    mapSize m_mapSize;

public:
    //map<Position, Enemy> m_enemiesPosition;
    map<Position, Field> fields;
    Position playerPosition = Position {0, 0};

    Map(int x_size, int y_size);

    mapSize getMapSize();

    void spawnEnemies(Enemy& enemy);
    void showMap() const;

    void spawnWeapons(Weapon& weapons);
};
#endif