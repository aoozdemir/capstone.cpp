#ifndef TILE_H
#define TILE_H

#include <string>
#include <vector>
#include "block.h"

enum TileType {
    grass,
    iron,
    copper,
    stone,
    coal,
};

class Tile {
   public:
    Tile();
    ~Tile();

   protected:
    TileType _type;

    int _id;
    int _posX, _posY;
    double _capacity;
    bool _isOccupied;
    // std::shared_ptr<Block> block;

   private:
    // static int _idCnt; // global variable for counting object ids
};

#endif
