#ifndef TILE_H
#define TILE_H

#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include "block.h"

class Block;

enum TileType {
    grass,
    iron,
    copper,
    stone,
    coal,
};

static const char *TileStr[] = {
    "Grass",
    "Iron",
    "Copper",
    "Stone",
    "Coal",
};

class Tile {
   public:
    Tile();
    Tile(int _id, int _posX, int _posY, bool _isOccupied);

    int getId() { return _id; };
    int getPosX() { return _posX; };
    int getPosY() { return _posY; };
    double getCapacity() { return _capacity; };
    void removeCapacity(double output, double old_cap) { _capacity = old_cap - output; };
    int getStatus() { return _isOccupied; };
    std::string getType() { return TileStr[_type]; };
    void placeBlock(Block *block);
    // std::shared_ptr<Tile> get_shared_this() { return shared_from_this(); }

   protected:
    int _id;

   private:
    TileType _type;

    int _posX, _posY;
    double _capacity;
    bool _isOccupied;
    Block *_block;
    // std::vector<std::thread> threads;
    // std::shared_ptr<Tile> _tile;
    // static std::mutex _mtx;
};

#endif
