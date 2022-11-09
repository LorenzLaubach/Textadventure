
#include "include/Game.h"

using namespace std;

int main() {
#ifdef DEBUG
    print("Now running in Debugging Mode");
    debug = true;
#endif
    srand(time(nullptr));
    Game textAdventure(3,3);
    textAdventure.play();
    return 0;
}
