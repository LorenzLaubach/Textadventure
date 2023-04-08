#include <iostream>
#include "common/random_generator.h"

int main() {
    int one = 0;
    int two = 0;
    int three = 0;

    for (int i = 0; i < 100; i++) {
        switch (getRandomNumber(0, 2)) {
            case 0:
                one++;
                break;
            case 1:
                two++;
                break;
            case 2:
                three++;
                break;
        }
    }
        std::cout << "One: " << one << std::endl;
        std::cout << "Two: " << two << std::endl;
        std::cout << "Three: " << three << std::endl;

    return 0;
}