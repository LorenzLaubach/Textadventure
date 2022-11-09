#include <map.h>

Map::Map(int x_size, int y_size) :
    m_mapSize({x_size - 1,y_size - 1}){
    // Build the map, so we have a Field Object for every possible Position
    for (int i = 0; i < m_mapSize.m_xSize; i++) {
        for (int j = 0; j < m_mapSize.m_ySize; j++) {
            fields.insert(pair<Position, Field>({i, j}, Field()));
        }
    }
}

mapSize Map::getMapSize() {
    return m_mapSize;
}

void Map::spawnEnemies(Enemy& enemy) {
    Position randPos{};
    if (debug) {
        randPos.x = 1;
        randPos.y = 1;
    }
    else {
        randPos = randPosition(
                enemy.m_spawnBound.xMinSpawn,
                enemy.m_spawnBound.yMinSpawn,
                enemy.m_spawnBound.xMaxSpawn,
                enemy.m_spawnBound.yMaxSpawn);
    }
    this->fields.at(randPos).p_enemy = &enemy;
    this->fields.at(randPos).has_enemy = true;
}

void Map::spawnWeapons(Weapon& weapon) {
    bool placable = false;
    Position randPos{};
    while(!placable) {
    if (debug) {
        randPos = Position( {0,1});
    }
    else {
        randPos = randPosition(
            weapon.m_spawnBound.xMinSpawn,
            weapon.m_spawnBound.yMinSpawn,
            weapon.m_spawnBound.xMaxSpawn,
            weapon.m_spawnBound.yMaxSpawn);
    }
        if (!fields.at(randPos).has_enemy) {
            fields.at(randPos).p_object = &weapon;
            fields.at(randPos).has_item = true;
            placable = true;
        }
    }
}

void Map::showMap() const {
    print("Your current Position is marked with an X");
    for (int j = 0; j <= m_mapSize.m_xSize; j++) {
        for (int i = 0; i <= m_mapSize.m_ySize; i++) {
            if (i == playerPosition.x && j == playerPosition.y){
                std::cout << "[X]";
            }
            else {
                std::cout << "[ ]";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

