#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <map>
#include "map.hpp"
#include "objects.h"
#include "printing.h"
#include <chrono>
#include <thread>
#include <variant>

using namespace std;

class Player {
private:
    string m_name;
    std::vector<Weapon> m_items;
    Map* m_map;
    Position m_lastPosition;

public:
    bool m_isPlaying = true;
    float m_life = 100;
    Weapon* m_activeWeapon;

    //Constructor
    explicit Player(Map& map) :
    m_map(&map),
    m_lastPosition({0,0})
    {
        print("Welcome to FunkyLoLos Textadventure");
        m_items.emplace_back(Weapon("Axe", 1, 5));
        m_activeWeapon = &m_items.at(0);
    }

    void setName(const string& playerName) {
        m_name = playerName;
    }

    void move(const int direction, map<int, string>& directoryMap) {
        m_lastPosition = m_map->m_playerPosition;
        if (directoryMap[direction] == "East") {
            m_map->m_playerPosition.x++;
            }
        else if (directoryMap[direction] == "South") {
            m_map->m_playerPosition.y++;
            }
        else if (directoryMap[direction] == "West")  {
            m_map->m_playerPosition.x--;
            }
        else if (directoryMap[direction] == "North") {
            m_map->m_playerPosition.y--;
            }
        else {
            print("This was not a valid Input");

            std::chrono::milliseconds timespan(2000);
            this_thread::sleep_for(timespan);
            print("Du Idiot");
            chooseDirectory();
            }

        print("...walking...");
        std::chrono::milliseconds timespan(1000);
        this_thread::sleep_for(timespan);

        if (m_map->m_enemiesPosition.find(m_map->m_playerPosition) == m_map->m_enemiesPosition.end()) {
            // not found
            print("Nothing to see here. Probably the lazy Creator didn't care for your fun");
        } else {
            // found
            print(
                    "Yikes there is a" +
                    m_map->m_enemiesPosition.at(m_map->m_playerPosition).m_name +
                    "in front of you");
            cout << m_map->m_enemiesPosition.at(m_map->m_playerPosition).m_picture << endl;

            print("What do you want to do now?");
            chooseFightAction(m_map->m_enemiesPosition.at(m_map->m_playerPosition));
        }
    }

    void chooseFightAction(Enemy& enemy) {
        printSelection(std::vector<string> {"Fight", "Flee like a Fly", "Inventory"});
        switch(playerInput(1,3)) {
            case 1: {
                fight(enemy);
                break;
            }
            case 2: {
                print("Walking back to old Position :(");
                m_map->m_playerPosition = m_lastPosition;
                break;
            }
            case 3: {
                showInventory();
                chooseFightAction(enemy);
                break;
            }
            default: {
                print("You can only type in the number 1 - 3 to select your action");
                wait(2000);
                print("Du Idiot");
            };
        }

    }

    void chooseAction() {
        printSelection(std::vector<string> {"Move", "Inventory", "Exit"});
        switch (playerInput(1,3)) {
            case 1: {
                this->chooseDirectory();
                break;
            }
            case 2: {
                this->showInventory();
                break;
            }
            case 3: {
                this->exitGame();
                break;
            }
            default: {
                print("You can only type in the number 1 - 3 to select your action");
                std::chrono::milliseconds timespan(1000);
                this_thread::sleep_for(timespan);
                print("Du Idiot");
            };
        }
    }

    void chooseDirectory() {
        vector<string> actions;
        map<int, string> directoryMap;
        int i = 1;
        if (this->m_map->getMapSize().m_xSize > this->m_map->m_playerPosition.x) {
            actions.emplace_back("East");
            directoryMap.insert(pair<int, string>(i, "East"));
            i++;
        }
        if(this->m_map->m_playerPosition.x > 0) {
            actions.emplace_back("West");
            directoryMap.insert(pair<int, string>(i, "West"));
            i++;
        }
        if (this->m_map->getMapSize().m_ySize > this->m_map->m_playerPosition.y) {
            actions.emplace_back("South");
            directoryMap.insert(pair<int, string>(i, "South"));
            i++;
        }
        if(this->m_map->m_playerPosition.y > 0) {
            actions.emplace_back("North");
            directoryMap.insert(pair<int, string>(i, "North"));
            i++;
        }
        printSelection(actions);
        this->move(playerInput(1,i), directoryMap);
    }

    void showInventory() {
        for (const Object& item: this->m_items) {
            print(item.m_name);
        }
    }

    void fight(Enemy enemy) {

        // Attacking Enemy
        print("Attacking Enemy...");
        enemy.m_life = enemy.m_life - m_activeWeapon->m_damage;
        print("Attacking with " + m_activeWeapon->m_name);
        print("...");
        wait(1000);
        print("You dealt " + to_string(m_activeWeapon->m_damage) + " damage");

        if(enemy.m_life <= 0) {
            print("Congratulations, the Enemy was defeated");
            goto FightEnd;
        }

        wait(2000);

        print("Enemy is attacking you");
        m_life = m_life - enemy.m_damage;
        print("...");
        wait(1000);
        print("Enemy dealt " + to_string(enemy.m_damage) + " damage");
        if(m_life <= 0) {
            print("You died");
            m_isPlaying = false;
            goto FightEnd;
        }
        print("Do you want to keep fighting?");
        chooseFightAction(enemy);

        FightEnd: ;
    }

    void exitGame() {
        m_isPlaying = false;
        print("Leaving the most fun Game ever for whatever reason");
    }

    void dead() {
        print("Game Over");
        this->m_isPlaying = false;
    }

};
#endif
