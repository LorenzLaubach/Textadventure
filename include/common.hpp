//
// Created by lorenz on 26.04.22.
//

#ifndef TEXTADVENTURE_COMMON_HPP
#define TEXTADVENTURE_COMMON_HPP
struct Position {
public:
    int x;
    int y;
};

static bool debug;

struct spawnBoundaries {
    int xMinSpawn, yMinSpawn, xMaxSpawn, yMaxSpawn;
};

// This is needed for a struct datatype to work in a map datatype
inline bool operator<(const Position& l, const Position& r) {
    return (l.x<r.x || (l.x==r.x && l.y<r.y));
}

struct mapSize {
    int m_xSize;
    int m_ySize;
};

inline int randNumbers(const int& minimum, int maximum) {
    maximum = maximum - minimum;
    int randomNumber = minimum + (rand() % (maximum+1));
    return randomNumber;
}

inline Position randPosition(const int& x_min,const int& y_min, const int& x_max, const int& y_max) {
    // Returns a random Position Object which can not be 0
    Position position{0,0};
    while(position.x == 0 && position.y == 0) {
        position.x = randNumbers(x_min, x_max);
        position.y = randNumbers(y_min, y_max);
    }
    return position;
}

#endif //TEXTADVENTURE_COMMON_HPP
