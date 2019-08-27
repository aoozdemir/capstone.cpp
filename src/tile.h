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
    Tile(int _posX, int _posY, bool _isOccupied);

    int getId() { return _id; };
    int getPosX() { return _posX; };
    int getPosY() { return _posY; };
    int getStatus() { return _isOccupied; };

   protected:
    int _id;
    // std::shared_ptr<Block> block;

   private:
    TileType _type;

    int _posX, _posY;
    double _capacity;
    bool _isOccupied;
    // static int _idCnt; // global variable for counting object ids
};

#endif
