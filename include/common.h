//
// Created by lorenz on 26.04.22.
//

#ifndef TEXTADVENTURE_COMMON_H
#define TEXTADVENTURE_COMMON_H
struct Position {
public:
    int x;
    int y;
};

// This is needed for a struct datatype to work in a map datatype
bool operator<(const Position& l, const Position& r) {
    return (l.x<r.x || (l.x==r.x && l.y<r.y));
}

struct mapSize {
    int m_xSize;
    int m_ySize;
};

#endif //TEXTADVENTURE_COMMON_H
