#pragma once
#include "objects.h"
#include "common/printing.hpp"

class Weapon : public spawnableObject {
public:
    int m_damage;

    Weapon(const std::string name, const std::string picture, spawnBoundaries spawnBound,
           const int &damage)
           : spawnableObject(name, picture, spawnBound),
           m_damage(damage){};
    ~Weapon() = default;

    void inspectByPlayer() override {
        print("");
    };
};