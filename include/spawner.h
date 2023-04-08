#pragma once

#include <map.h>
#include "enemy/Enemy.h"
#include "items/weapon.h"
#include <objects.h>
#include "enemy/dragon.h"
#include "enemy/troll.h"
#include "enemy/bug.h"
#include "items/sword.h"

class Spawner {
private:
    Map* p_map;
    Weapon* m_sword;
    Enemy* m_troll;
    Enemy* m_bug;
    Enemy* m_dragon;
    Riddler* m_riddler;

public:
    explicit Spawner(Map& map) {
        p_map = &map;

        m_troll = new Troll();
        spawnEnemy(m_troll);

        m_bug = new Bug();
        spawnEnemy(m_bug);

        m_dragon = new Dragon();
        spawnEnemy(m_dragon);

        m_sword = new Sword();
        spawnObject(m_sword);

        m_riddler = new Riddler();
        spawnRiddler(m_riddler);
    }

    ~Spawner() {
        delete m_sword;
        delete m_troll;
        delete m_bug;
        delete m_dragon;
    }

    void spawnEnemy(Enemy* enemy) {
        bool placable = false;
        while(!placable) {
            enemy->setSpawnPosition();
            if (p_map->fields.at(enemy->m_spawnPosition).isFree) {
                p_map->fields.at(enemy->m_spawnPosition).p_enemy = enemy;
                p_map->fields.at(enemy->m_spawnPosition).isFree = false;
                p_map->fields.at(enemy->m_spawnPosition).has_enemy = true;
                placable = true;
            }
        }
    }
    
    void spawnRiddler(Riddler* riddler) {
        bool placable = false;
        while(!placable) {
            riddler->setSpawnPosition();
            if (p_map->fields.at(riddler->m_spawnPosition).isFree) {
                p_map->fields.at(riddler->m_spawnPosition).p_riddler = riddler;
                p_map->fields.at(riddler->m_spawnPosition).isFree = false;
                p_map->fields.at(riddler->m_spawnPosition).has_riddler = true;
                placable = true;
            }
        }
    }
    
    void spawnObject(Weapon* object) {
        bool placable = false;
        while(!placable) {
            object->setSpawnPosition();
            if (p_map->fields.at(object->m_spawnPosition).isFree) {
                p_map->fields.at(object->m_spawnPosition).p_object = object;
                p_map->fields.at(object->m_spawnPosition).isFree = false;
                p_map->fields.at(object->m_spawnPosition).has_item = true;
                placable = true;
            }
        }
    }
};
