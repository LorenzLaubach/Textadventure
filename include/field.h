#include "enemy/Enemy.h"

struct Field {
    bool has_enemy = false;
    bool isFree = true;
    spawnableObject* p_someObject = nullptr;
    Enemy* p_enemy = nullptr;
    bool has_item = false;
    Weapon* p_object = nullptr;
};