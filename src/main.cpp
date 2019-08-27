#include <iostream>
#include <thread>
#include <vector>

#include "map.h"

int main() {
    std::cout << "Hello World!"
              << "\n";

    Map *map = new Map();
    Map *_4map = new Map(2);
    Map *_9map = new Map(3);

    map->createTiles();
    _4map->createTiles();
    _9map->createTiles();
    std::cout << map->getTileCount() << ".\n";
    for (auto &&tile : map->getTiles()) {
        std::cout << "("
                  << tile.getPosX()
                  << ", "
                  << tile.getPosY()
                  << ")"
                  << "\n";
    }

    std::cout << _4map->getTileCount() << ".\n";

    std::cout << _9map->getTileCount() << ".\n";
    for (auto &&tile : _9map->getTiles()) {
        std::cout << "("
                  << tile.getPosX()
                  << ", "
                  << tile.getPosY()
                  << ")"
                  << "\n";
    }
    return 0;
}
