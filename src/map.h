#ifndef MAP_H
#define MAP_H

#include <future>
#include <string>
#include <thread>
#include <vector>
#include "tile.h"

class Map {
   public:
    Map();
    Map(int size);

    int getSize() { return _size; }
    void createTiles();
    std::vector<std::shared_ptr<Tile>> getTiles() { return tiles; }
    int getTileCount() { return tiles.size(); };
    void simulate();

   protected:
    int _seed;
    int _size;

   private:
    std::vector<std::shared_ptr<Tile>> tiles;
    std::vector<std::thread> threads;
    static std::mutex _mtx;
    std::vector<std::future<void>> futures;
};

#endif
