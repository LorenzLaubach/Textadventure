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
#ifdef DEBUG
            Position randPosit({1,1});
#else
            Position randPosit = randPosition(
                    enemy.m_spawnBound.xMinSpawn,
                    enemy.m_spawnBound.yMinSpawn,
                    enemy.m_spawnBound.xMaxSpawn,
                    enemy.m_spawnBound.yMaxSpawn);
#endif
            this->fields.at(randPosit).p_enemy = &enemy;
            this->fields.at(randPosit).has_enemy = true;
        }

void Map::spawnWeapons(Weapon& weapon) {
            bool placable = false;
            while(!placable) {
#ifdef DEBUG
                Position randPosit = Position( {0,1});
#else
                Position randPosit = randPosition(
                    weapon.m_spawnBound.xMinSpawn,
                    weapon.m_spawnBound.yMinSpawn,
                    weapon.m_spawnBound.xMaxSpawn,
                    weapon.m_spawnBound.yMaxSpawn);
#endif
                if (!fields.at(randPosit).has_enemy) {
                    fields.at(randPosit).p_object = &weapon;
                    fields.at(randPosit).has_item = true;
                    placable = true;
                }
            }
        }

void Map::showMap() const {
    print("Your current Position is marked with an X");
    for (int i = 0; i <= m_mapSize.m_xSize; i++) {
        for (int j = 0; j <= m_mapSize.m_ySize; j++) {
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

