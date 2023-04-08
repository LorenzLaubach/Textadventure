#include <map.h>

Map::Map(int x_size, int y_size) :
    m_mapSize({x_size,y_size}){
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

void Map::showMap() const {
    print("Your current Position is marked with an X");
    for (int j = 0; j < m_mapSize.m_xSize; j++) {
        for (int i = 0; i < m_mapSize.m_ySize; i++) {
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

