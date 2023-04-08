#ifndef UNTITLED_OBJECTS_H
#define UNTITLED_OBJECTS_H
#include <string>
#include "common/random_generator.h"

enum class objectType {
    ENEMY = 1,
    WEAPON = 2,
    DRINK = 3,
    RIDDLER = 4,
};


class spawnableObject {
public:
    spawnableObject(const std::string name, const std::string picture, spawnBoundaries spawnBound)
    : m_name(name),
    m_picture(picture),
    m_spawnBound(spawnBound)
    {};

    virtual ~spawnableObject() = default;

    std::string m_name;
    std::string m_picture;
    spawnBoundaries m_spawnBound;
    Position m_spawnPosition = {0,0};

    virtual void inspectByPlayer() = 0;

    void setSpawnPosition() {
        m_spawnPosition = randPosition(
                    m_spawnBound.m_xMinSpawn,
                    m_spawnBound.m_yMinSpawn,
                    m_spawnBound.m_xMaxSpawn,
                    m_spawnBound.m_yMaxSpawn);
    }
};
#endif //UNTITLED_OBJECTS_H
