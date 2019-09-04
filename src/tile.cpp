#include "tile.h"
#include <iostream>
#include <random>
#include "block.h"
#include "map.h"
// #include "Intersection.h"
// #include "Street.h"

Tile::Tile() {
    _id = 1;
}

Tile::Tile(int id, int posX, int posY, bool isOccupied) {
    _id = id;
    _posX = posX;
    _posY = posY;
    _isOccupied = isOccupied;
    _type = static_cast<TileType>(rand() % 4);

    if (_type == TileType::grass) {
        _capacity = 0;
    } else {
        _capacity = rand() % 1000 + 100;
    }
}

void Tile::placeBlock(Block *block) {
    _isOccupied = true;
    _block = block;
    std::shared_ptr shared_tile = std::make_shared<Tile>(*this);
    block->setPlacedOn(shared_tile);
}
