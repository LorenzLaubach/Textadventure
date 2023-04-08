#ifndef MAP_H
#define MAP_H
#include <vector>
#include <map>
#include "common/printing.hpp"
#include "common/common.hpp"
#include <enemy/Enemy.h>
#include "items/weapon.h"
#include "common/random_generator.h"
#include "riddler.h"

struct Field {
    bool has_enemy = false;
    bool isFree = true;
    Enemy* p_enemy = nullptr;
    bool has_item = false;
    Weapon* p_object = nullptr;
    bool has_riddler = false;
    Riddler* p_riddler = nullptr;
};

class Map {
private:
    mapSize m_mapSize;

public:
    map<Position, Field> fields;
    Position playerPosition = Position {0, 0};

    Map(int x_size, int y_size);

    mapSize getMapSize();

    void showMap() const;
};
#endif