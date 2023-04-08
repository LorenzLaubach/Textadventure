#include "common/common.hpp"
#include "include/Game.h"

using namespace std;

int main() {
#ifdef DEBUG
    print("Now running in Debugging Mode");
    debug = true;
#endif
    Game textAdventure(3,3);
    textAdventure.play();
    return 0;
}
