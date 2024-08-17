#include <iostream>
#include <vector>

#include "Battle.h"


int main() {
    try {
        Battle battle;
        battle.startGameLoop();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }
    return 0;
}
