#include "tile.h"
#include <iostream>
#include <random>
#include "map.h"
// #include "Intersection.h"
// #include "Street.h"

Tile::Tile() {
    _id = 1;
}

Tile::Tile(int posX, int posY, bool isOccupied) {
    _id = 1;
    _posX = posX;
    _posY = posY;
    _isOccupied = isOccupied;
}
