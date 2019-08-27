#include "map.h"
#include <iostream>
#include <random>
#include <math.h>
#include "tile.h"
// #include "Intersection.h"
// #include "Street.h"

Map::Map() {
    _seed = 1;
    _size = 1;
}

Map::Map(int size) {
    _seed = 1;
    _size = size;
}

void Map::createTiles() {
    int size = this->getSize();

    if (size == 1) {
        Tile *tile = new Tile(
            0, 0, false
        );
        this->tiles.push_back(*tile);
    } else if (size > 1) {
        // int sqr = std::pow(size + 1, 2.0);

        for(size_t i = 0; i < size; i++) {
            for(size_t j = 0; j < size; j++) {
                Tile *tile = new Tile(
                    i, j, false
                );
                this->tiles.push_back(*tile);
            }
        }
    }
}