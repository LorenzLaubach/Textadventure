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

int randNumbers(const int& minimum, int maximum) {
    maximum = maximum - minimum;
    int randomNumber = minimum + (rand() % (maximum+1));
    return randomNumber;
}

Position randPosition(const int& minimum, int maximum) {
    // Returns a random Position Object which can not be 0
    Position position{0,0};
    while(position.x == 0 && position.y == 0) {
        position.x = randNumbers(minimum, maximum);
        position.y = randNumbers(minimum, maximum);
    }
    return position;
}

#endif //TEXTADVENTURE_COMMON_H
