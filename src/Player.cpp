#include "Player.h"
#include "items/weapon.h"

//Constructor
Player::Player(Map &map) :
        m_map(&map),
        m_lastPosition({0, 0}) {
    print("Welcome to FunkyLoLos Textadventure");
    initWeapon = new Axe();
    m_weapons.emplace_back(*initWeapon);
    activeWeapon = initWeapon;
    if (debug) {
        print("Enter your Name");
        cin >> m_name;
        print("Hello there " + m_name);
    }
}

void Player::setName(const string &name) {
    m_name = name;
}

Field& Player::getPlayerPosition() {
    return m_map->fields.at(m_map->playerPosition);
}

void Player::move(const int direction, map<int, string> &directoryMap) {
    m_lastPosition = m_map->playerPosition;
    if (directoryMap[direction] == "East") {
        m_map->playerPosition.x++;
    } else if (directoryMap[direction] == "South") {
        m_map->playerPosition.y++;
    } else if (directoryMap[direction] == "West") {
        m_map->playerPosition.x--;
    } else if (directoryMap[direction] == "North") {
        m_map->playerPosition.y--;
    } else {
        print("This was not a valid Input");
        wait(2000);
        print("Du Idiot");
        chooseDirectory();
    }

    print("...walking...");
    wait(1000);

    inspectingField();
}

void Player::inspectingField() {

    Field activeField = getPlayerPosition();
    
    if(activeField.has_enemy) {
        activeField.p_enemy->inspectByPlayer();
        chooseFightAction(*activeField.p_enemy);
    }
    else if(activeField.has_item) {
        activeField.p_object->inspectByPlayer();
        pickupItem(*activeField.p_object);
    }
    else if(activeField.has_riddler) {
        activeField.p_riddler->inspectByPlayer();
        solveRiddle(*activeField.p_riddler);
    }
    else if(activeField.isFree) {
        print("Nothing to see here. Probably the lazy Creator didn't care for your fun");
    }
}

void Player::pickupItem(Weapon& item) {
    m_weapons.push_back(item);
    m_map->fields.at(m_map->playerPosition).p_object = nullptr;
    m_map->fields.at(m_map->playerPosition).has_item = false;
    m_map->fields.at(m_map->playerPosition).isFree = false;
}

void Player::chooseFightAction(Enemy& enemy) {
    printSelection(std::vector<string>{"Fight", "Flee like a Fly", "Inventory"});
    switch (playerInput(1, 3)) {
        case 1: {
            fight(enemy);
            break;
        }
        case 2: {
            print("Walking back to old Position :(");
            m_map->playerPosition = m_lastPosition;
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

void Player::chooseAction() {
    printSelection(std::vector<string>{"Move", "Inventory", "Exit"});
    switch (playerInput(1, 3)) {
        case 1: {
            chooseDirectory();
            break;
        }
        case 2: {
            showInventory();
            break;
        }
        case 3: {
            exitGame();
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

void Player::chooseDirectory() {
    vector<string> actions;
    map<int, string> directoryMap;
    int i = 1;
    if (m_map->getMapSize().m_xSize - 1 > m_map->playerPosition.x) {
        actions.emplace_back("East");
        directoryMap.insert(pair<int, string>(i, "East"));
        i++;
    }
    if (m_map->playerPosition.x > 0) {
        actions.emplace_back("West");
        directoryMap.insert(pair<int, string>(i, "West"));
        i++;
    }
    if (m_map->getMapSize().m_ySize - 1> m_map->playerPosition.y) {
        actions.emplace_back("South");
        directoryMap.insert(pair<int, string>(i, "South"));
        i++;
    }
    if (m_map->playerPosition.y > 0) {
        actions.emplace_back("North");
        directoryMap.insert(pair<int, string>(i, "North"));
        i++;
    }
    printSelection(actions);
    move(playerInput(1, i), directoryMap);
}

void Player::showInventory() {
    printf("%-20s%s\n", "Weapons:", "Damage:");
    for (const Weapon &item: m_weapons) {
        printf("%-20s%s\n", item.m_name.c_str(), to_string(item.m_damage).c_str());
    }
    printSelection({"Switch Weapons", "Use Item", "See Map", "Back"});
    switch (playerInput(1, 4)) {
        case 1: { // Switch Weapons
            switchWeapons();
            break;
        }
        case 2: { // Use Item
            // useItem() TODO implement a useItem FUnction
            print("Nice Try but not yet implemented. But the Creator of this game will "
                  "code this feature in a blink of an eye");
            break;
        }
        case 3: { // See map
            m_map->showMap();
            break;
        }
        case 4: {
            break;
        }
        default: {
            print("You can only type in the number 1 - 4 to select your action");
            wait(2000);
            print("Du Idiot");
        };
    }
}

void Player::switchWeapons() {
    print("Type in Weapon Name you want to use or type X to cancel");
    Weapon *currentWeapon = activeWeapon;
    bool switched = false;
    while (!switched) { // Loop will continue until User set valid Input
        string userWeapon;
        cin >> userWeapon;
        for (Weapon &weapon: m_weapons) {
            if (userWeapon == weapon.m_name && userWeapon != activeWeapon->m_name) {
                activeWeapon = &weapon;
                switched = true;
                break;
            }
        }
        if (switched) {
            print("Now using " + activeWeapon->m_name);
        } else if (userWeapon == "x" || userWeapon == "X") {
            print("Cancelling");
            break;
        } else {
            print("Your Input didn't match any Weapon you possess or you already use it, try again");
        }
    }
}

void Player::fight(Enemy& enemy) {

    attackEnemy(enemy);

    if (enemy.m_life <= 0) {
        enemy.defeated(this->m_name);
        print("Congratulations, the Enemy was defeated");
        // Remove the Enemy from field as it is defeated;
        m_map->fields.at(m_map->playerPosition).p_enemy = nullptr;
        m_map->fields.at(m_map->playerPosition).isFree = true;
        m_map->fields.at(m_map->playerPosition).has_enemy = false;
        goto FightEnd;
    }

    wait(2000);

    enemyAttackingPlayer(enemy);

    if (life <= 0) {
        print(this->m_name + " died, what a talentless loser, wait talent doesn't exists", 4);
        dead();
        goto FightEnd;
    }
    print("Do you want to keep fighting?");
    chooseFightAction(enemy);
    FightEnd:;
}

void Player::attackEnemy(Enemy &enemy) const {
    print("Attacking Enemy...");
    float damage = addBonusDamage();
    enemy.m_life = enemy.m_life - damage;
    print("Attacking with " + activeWeapon->m_name);
    print("...");
    wait(1000);
    print("You dealt " + to_string((int)damage) + " damage", 2);
    print(enemy.m_name + " has " + to_string((int) enemy.m_life) + " Lifepoints left");
}

float Player::addBonusDamage() const {
    if(getRandomNumber(1, whatAreTheOdds) == whatAreTheOdds) {
        std::cout << "******* Critical Hit *******" << std::endl;
        return (float)activeWeapon->m_damage*m_criticalHit;
    }
    else {
        return (float)activeWeapon->m_damage;
    }
}

void Player::enemyAttackingPlayer(Enemy& enemy) {
    print("Enemy is attacking you");
    life = life - getPlayerPosition().p_enemy->m_damage;
    print("...");
    wait(1000);
    print("Enemy dealt " + to_string((int)enemy.m_damage) + " damage", 4);
    print("You have " + to_string((int) life) + " Lifepoints left");
}

void Player::increaseExperience(const int xp) { //TODO implement it after fighting
    m_experience+=xp;
}

void Player::solveRiddle(Riddler &riddler) {
    if (riddler.askRiddle()) {
        print("Astonishing that was right. Usually you are more of a schnook" + m_name +
        ". Here is a little reward for you:");
        increaseCritChance(1);
    }
    else {
        print("This was wrong as expected you little dopey. Lets see if we see again");
        wait(700);
        print("See ya");
        m_map->fields.at(m_map->playerPosition).p_riddler = nullptr; // prob deprecated
        m_map->fields.at(m_map->playerPosition).isFree = true;
        m_map->fields.at(m_map->playerPosition).has_riddler = false;
        riddler.setSpawnPosition();
        m_map->fields.at(riddler.m_spawnPosition).p_riddler = &riddler; // prob deprecated
        m_map->fields.at(riddler.m_spawnPosition).isFree = false;
        m_map->fields.at(riddler.m_spawnPosition).has_riddler = true;
    }
}

void Player::increaseCritChance(const int& incr) {
    this->whatAreTheOdds = this->whatAreTheOdds - incr;
    string critChance = to_string((1/whatAreTheOdds)*100);
    print("Looks like your Critical Hit Chance is now " + critChance + "%");
}

void Player::dead() {
    print("Game Over");
    isPlaying = false;
}

void Player::exitGame() {
    isPlaying = false;
    print("Leaving the most fun Game ever for whatever reason");
}

Player::~Player() {
    delete initWeapon;
}
