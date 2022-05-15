#include <iostream>
#include <Player.hpp>
#include "./include/enemies.h"
#include "ASCII/troll.h"
#include "ASCII/sword.h"

using namespace std;


void initGame(Player& player, Map& map) {
    print("Enter your Name");
    string name;
    cin >> name;
    player.setName(name);
    cout << "Hello There " << name << endl;
}

int main() {
    srand(time(nullptr));
    Map map = Map(5, 5);
    Player player = Player(map);
    initGame(player, map);

    vector<Enemy> enemies;
    Enemy troll = Enemy("Troll", 10, 70, trollASCII);
    enemies.push_back(troll);
    map.spawnEnemies(enemies);

    vector<Weapon> objects;
    Weapon sword = Weapon("Sword", 1, 15, swordASCII);
    objects.push_back(sword);
    map.spawnWeapons(objects);

    int round = 0;
    while(player.m_isPlaying) {
        cout << "--------------------------\nRound" + to_string(round++) << endl;
        player.chooseAction();
    }
    return 0;
}

//todo switch weapons
//todo restructure Project so cpp and header files are seperated