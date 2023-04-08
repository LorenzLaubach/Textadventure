#ifndef TEXTADVENTURE_RANDOM_GENERATOR_H
#define TEXTADVENTURE_RANDOM_GENERATOR_H

#include <iostream>
#include <random>
#include "common/common.hpp"


static std::random_device rd;
static std::mt19937 gen(rd());

    static int getRandomNumber(int min, int max) {
        std::uniform_int_distribution<> distribution(min, max);
        return distribution(gen);
    }

    static Position randPosition(const int& x_min,const int& y_min, const int& x_max, const int& y_max) {
        // Returns a random Position Object which can not be 0
        Position position{0,0};
        while(position.x == 0 && position.y == 0) {
            position.x = getRandomNumber(x_min, x_max);
            position.y = getRandomNumber(y_min, y_max);
        }
        return position;
    }

#endif //TEXTADVENTURE_RANDOM_GENERATOR_H
