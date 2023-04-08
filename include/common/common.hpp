#ifndef TEXTADVENTURE_COMMON_HPP
#define TEXTADVENTURE_COMMON_HPP

#include <random>

struct Position {
public:
    int x;
    int y;
};

static bool debug = false;

struct spawnBoundaries {
    spawnBoundaries(int xMinSpawn,int yMinSpawn,int xMaxSpawn,int yMaxSpawn) :
    m_xMinSpawn(xMinSpawn),
    m_yMinSpawn(yMinSpawn),
    m_xMaxSpawn(xMaxSpawn),
    m_yMaxSpawn(yMaxSpawn) {};
    int m_xMinSpawn, m_yMinSpawn, m_xMaxSpawn, m_yMaxSpawn;
};

// This is needed for a struct datatype to work in a map datatype
inline bool operator<(const Position& l, const Position& r) {
    return (l.x<r.x || (l.x==r.x && l.y<r.y));
}

struct mapSize {
    int m_xSize;
    int m_ySize;
};

#endif //TEXTADVENTURE_COMMON_HPP
