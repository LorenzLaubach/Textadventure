#include <iostream>
#include <Player.hpp>
#include "./include/enemies.h"

using namespace std;


void initGame(Player& player, Map& map) {
    print("Enter your Name");
    string name;
    cin >> name;
    player.setName(name);
    cout << "Hello There " << name << endl;

    vector<Enemy> enemies;
    Enemy troll = Enemy("Troll", 10, 70);
    enemies.push_back(troll);
    map.spawnEnemies(enemies);
}

int main() {
    srand(time(nullptr));
    Map map = Map(5, 5);
    Player player = Player(map);
    initGame(player, map);
    int round = 0;
    while(player.m_isPlaying) {
        cout << "--------------------------\nRound" + to_string(round++) << endl;
        player.chooseAction();
    }
    return 0;
}


//todo Let Enemies spawn randomly at different Positions
//todo Can not use one instance of an enemy for multiple appearances due to different life sattus after fighting
//todo let different weapons spawn
//todo switch weapons
//