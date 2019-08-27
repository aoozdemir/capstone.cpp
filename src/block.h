#ifndef BLOCK_H
#define BLOCK_H

#include <mutex>
#include <string>
#include <vector>
#include "tile.h"

class Block {
   public:
    // constructor / desctructor
    Block();
    ~Block();

    // getter and setter
    // int getID() { return _id; }
    // void setPosition(double x, double y);
    // void getPosition(double &x, double &y);
    // ObjectType getType() { return _type; }

    // typical behaviour methods
    // virtual void simulate(){};

   protected:
    int _id;
    std::shared_ptr<Tile> _placedOn;
    bool _status;
    double _storage;
    double _rate;
    double _output_per_second;

    static std::mutex _mtx;

   private:
    // static int _idCnt; // global variable for counting object ids
};

#endif
