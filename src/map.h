#ifndef MAP_H
#define MAP_H

#include <future>
#include <string>
#include <vector>
#include "tile.h"

class Map {
   public:
    // constructor / desctructor
    Map();
    Map(int size);

    // getter and setter
    int getSize() { return _size; }
    void createTiles();
    std::vector<Tile> getTiles() { return tiles; }
    int getTileCount() { return tiles.size(); };
    // int getID() { return _id; }
    // void setPosition(double x, double y);
    // void getPosition(double &x, double &y);
    // ObjectType getType() { return _type; }

    // typical behaviour methods
    // virtual void simulate(){};

   protected:
    int _seed;
    int _size;

    // ObjectType _type;                 // identifies the class type
    // double _posX, _posY;              // vehicle position in pixels
    // static std::mutex _mtx;           // mutex shared by all traffic objects for protecting cout

   private:
    std::vector<Tile> tiles;

    // static int _idCnt; // global variable for counting object ids
};

#endif
