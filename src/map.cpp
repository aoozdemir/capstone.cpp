#include "map.h"
#include <math.h>
#include <iostream>
#include <random>
#include "tile.h"

class Tile;
class Block;

Map::Map() {
    _seed = 1;
    _size = 1;
}

Map::Map(int size) {
    _seed = 1;
    _size = size;
}

void Map::simulate() {
    // launch drive function in a thread
    for (auto &tile : this->getTiles()) {
        if (tile->getType() == "Grass") continue;
        std::cout << "Setting a miner on tile " << tile->getType() << "\t(" << tile->getId() << ")" << std::endl;
        Block *block = tile->getBlock();
        // futures.emplace_back(std::async(std::launch::any, &Block::mine, block));
        threads.emplace_back(std::thread(&Block::mine, block));
    }

    for_each(threads.begin(), threads.end(), [](std::thread &t) {
        t.join();
    });
    // for (const std::future<void> &ftr : futures)
    //     ftr.wait();
}

void Map::createTiles() {
    int size = this->getSize();

    if (size == 1) {
        std::shared_ptr tile = std::make_shared<Tile>(
            1, 0, 0, false);
        this->tiles.push_back(tile);
    } else if (size > 1) {
        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                std::shared_ptr tile = std::make_shared<Tile>(
                    (i * 3 + 1 + j), i, j, false);
                this->tiles.push_back(tile);
            }
        }
    }
}
