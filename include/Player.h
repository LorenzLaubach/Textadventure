#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <map>
#include "map.h"
#include "objects.h"
#include "printing.hpp"
#include <chrono>
#include <thread>
#include <variant>
#include <list>

using namespace std;

class Player {
private:
    string m_name;
    std::list<Weapon> m_items;
    Map* m_map;
    Position m_lastPosition;

public:
    bool isPlaying = true;
    float life = 100;
    Weapon* activeWeapon;

    //Constructor
    explicit Player(Map& map, const Weapon initWeapon);

    void setName(const string& name);

    void move(const int direction, map<int, string>& directoryMap);

    void inspectingField();

    void pickupItem(const Weapon& item);

    void chooseFightAction(Enemy& enemy);

    void chooseAction();

    void chooseDirectory();

    void showInventory();

    void switchWeapons();

    void fight(Enemy& enemy);

    void exitGame();

    void dead();

};
#endif
