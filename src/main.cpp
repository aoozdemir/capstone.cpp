#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <iostream>
#include <thread>
#include <vector>
#include "map.h"

int main() {
    srand(time(NULL));
    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

    Map *_9map = new Map(3);

    _9map->createTiles();

    std::cout << _9map->getTileCount() << ".\n";
    for (auto &tile : _9map->getTiles()) {
        std::cout << tile->getId()
                  << ": ("
                  << tile->getPosX()
                  << ", "
                  << tile->getPosY()
                  << ")"
                  << " \t: "
                  << tile->getType()
                  << "    \t: "
                  << tile->getCapacity()
                  << "\n";

        Block *block = new Block(tile->getId());
        tile->placeBlock(block);
    }

    _9map->simulate();
    return 0;
}
