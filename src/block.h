#ifndef BLOCK_H
#define BLOCK_H

#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include "tile.h"

class Tile;

class Block {
   public:
    // constructor / desctructor
    Block();
    Block(int id);

    // getter and setter
    int getID() { return _id; }
    int getOutput() { return _output_per_second; }
    int getStored() { return _storage; }
    void simulate();
    void setPlacedOn(std::shared_ptr<Tile> tile) { _placedOn = tile; };
    void addStorage(double input, double stored) { _storage = stored + input; };
    void mine();

    // std::shared_ptr<Block> get_shared_this() { return shared_from_this(); }

   private:
    std::shared_ptr<Tile> _placedOn;
    int _id;
    bool _status;
    double _storage;
    double _rate;
    double _output_per_second;
    std::vector<std::thread> threads;
    static std::mutex _mtx;
};

#endif
