#ifndef BLOCK_H
#define BLOCK_H

#include <mutex>
#include <string>
#include <vector>
#include "tile.h"

class Tile;

class Block {
   public:
    Block();
    Block(int id);

    double getID() { return _id; }
    double getOutput() { return _output_per_second; }
    double getStored() { return _storage; }
    void simulate();
    void setPlacedOn(std::shared_ptr<Tile> tile) { _placedOn = tile; };
    void addStorage(double input, double stored) { _storage = stored + input; };
    void mine();

   private:
    std::shared_ptr<Tile> _placedOn;
    int _id;
    bool _status;
    double _storage;
    double _rate;
    double _output_per_second;
};

#endif
