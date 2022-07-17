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
    map<Position, Field> fields;
    Position playerPosition = Position {0, 0};

    Map(int x_size, int y_size) :
            m_mapSize({x_size - 1,y_size - 1}){
        // Build the map, so we have a Field Object for every possible Position
        for (int i = 0; i <= x_size; i++) {
            for (int j = 0; j <= y_size; j++) {
                Field field;
                fields.insert(pair<Position, Field>({i, j}, field));
            }
        }
    }

    mapSize getMapSize() {
        return m_mapSize;
    }

    void spawnEnemies(std::vector<Enemy>& enemies) { // ToDo the Enemy or Item Class should have a spawn function
        for (Enemy& enemy : enemies) {
            if (enemy.m_name == "Troll") {
#ifdef DEBUG
                Position randPosit({1,1});
#else
                Position randPosit = randPosition(0,1);
#endif
                this->fields.at(randPosit).p_enemy = &enemy;
                this->fields.at(randPosit).has_enemy = true;
            }
        }
    }

    void showMap() {
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

    void spawnWeapons(std::vector<Weapon>& weapons) {
        for (Weapon& weapon : weapons) {
            if (weapon.m_name == "Sword") {
                bool placable = false;
                while(!placable) {
#ifdef DEBUG
                    Position randPosit = Position( {0,1});
#else
                    Position randPosit = randPosition(0,1);
#endif
                    if (!fields.at(randPosit).has_enemy) {
                        fields.at(randPosit).p_object = &weapon;
                        fields.at(randPosit).has_item = true;
                        placable = true;
                    }
                }
            }
        }
    }

};
#endif