#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "tile.h"

class Map {
   public:
    // constructor / desctructor
    Map();
    ~Map();

    // getter and setter
    // int getID() { return _id; }
    // void setPosition(double x, double y);
    // void getPosition(double &x, double &y);
    // ObjectType getType() { return _type; }

    // typical behaviour methods
    // virtual void simulate(){};

   protected:
    int _seed;
    int _size;
    std::vector<std::shared_ptr<Tile>> tiles;

    // ObjectType _type;                 // identifies the class type
    // double _posX, _posY;              // vehicle position in pixels
    // static std::mutex _mtx;           // mutex shared by all traffic objects for protecting cout

   private:
    // static int _idCnt; // global variable for counting object ids
};

#endif
