#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <map>
#include "map.h"
#include "objects.h"
#include "common/printing.hpp"
#include <chrono>
#include <thread>
#include <variant>
#include <list>
#include "enemy/Enemy.h"
#include "items/Axe.h"

using namespace std;

class Player {
private:
    string m_name;
    std::vector<spawnableObject> m_items;
    std::vector<Weapon> m_weapons;
    Map* m_map;
    Position m_lastPosition;
    Weapon* initWeapon;
    int m_experience;
    int whatAreTheOdds = 2;
    float m_criticalHit = 1.5;

    Field& getPlayerPosition();

public:
    bool isPlaying = true;
    float life = 100;
    Weapon* activeWeapon;

    Player(Map& map);

    ~Player();

    void increaseExperience(int xp);

    void setName(const string& name);

    void move(int direction, map<int, string>& directoryMap);

    void inspectingField();

    void pickupItem(Weapon& item);

    void chooseFightAction(Enemy& enemy);

    void solveRiddle(Riddler& riddler);

    void chooseAction();

    void chooseDirectory();

    void showInventory();

    void switchWeapons();

    void fight(Enemy& enemy);

    void attackEnemy(Enemy& enemy) const;

    float addBonusDamage() const;

    void enemyAttackingPlayer(Enemy& enemy);

    void exitGame();

    void dead();

    void increaseCritChance(const int &incr);
};
#endif
