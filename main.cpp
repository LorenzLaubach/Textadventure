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
    Map map = Map(2, 2);
    Player player = Player(map);
#ifdef DEBUG
    print("Now running in Debugging Mode");
    player.setName("Debugger");
#else
    initGame(player, map);
#endif

    vector<Enemy> enemies;
    Enemy troll = Enemy("Troll", 10, 70, trollASCII);
    enemies.push_back(troll);
    map.spawnEnemies(enemies);

    vector<Weapon> objects;
    Weapon sword = Weapon("Sword", 1, 15, swordASCII);
    objects.push_back(sword);
    map.spawnWeapons(objects);

    int round = 1;
    while(player.isPlaying) {
        changeColour(2);
        cout << "--------------------------\nRound" + to_string(round++) << endl;
        changeColour(15);
        player.chooseAction();
    }
    return 0;
}

//todo switch weapons
//todo restructure Project so cpp and header files are seperated