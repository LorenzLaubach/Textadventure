#ifndef MAP_H
#define MAP_H
#include <vector>
#include <map>
#include "enemies.h"
#include "printing.h"
#include "common.h"
#include <objects.h>


struct Field {
    bool has_enemy = false;
    Enemy* p_enemy;
    bool has_item = false;
    Weapon* p_object;

    void setEnemy(Enemy& enemy) {
        if(has_enemy) {
            print("Two Enemies can not be set on the same Field");
        }
        else {
            p_enemy = &enemy;
            has_enemy = true;
        }
    }
};

class Map {
private:
    mapSize m_mapSize;

public:
    //map<Position, Enemy> m_enemiesPosition;
    map<Position, Field> m_fields;
    Position m_playerPosition = Position {0,0};

    Map(int x_size, int y_size) {
        // Initialize the size of the map
        m_mapSize.m_xSize = x_size;
        m_mapSize.m_ySize = y_size;

        // Build the map, so we have a Field Object for every possible Position
        for (int i = 0; i < x_size; i++) {
            for (int j = 0; j < y_size; j++) {
                Field field;
                m_fields.insert(pair<Position, Field>({i,j}, field));
            }
        }
    }

    mapSize getMapSize() {
        return m_mapSize;
    }

    void spawnEnemies(std::vector<Enemy>& enemies) {
        for (Enemy& enemy : enemies) {
            if (enemy.m_name == "Troll") {
                Position randPosit = randPosition(0,1);
                this->m_fields.at(randPosit).p_enemy = &enemy;
                this->m_fields.at(randPosit).has_enemy = true;
            }
        }
    }

    void spawnWeapons(std::vector<Weapon>& weapons) {
        for (Weapon& weapon : weapons) {
            if (weapon.m_name == "Sword") {
                bool placable = false;
                while(!placable) {
                    Position randPosit = randPosition(0,1);
                    if (!m_fields.at(randPosit).has_enemy) {
                        m_fields.at(randPosit).p_object = &weapon;
                        m_fields.at(randPosit).has_item = true;
                        placable = true;
                    }
                }
            }
        }
    }

};
#endif