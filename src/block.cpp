#include "block.h"
#include <unistd.h>
#include <iostream>
#include <random>
#include "tile.h"

Block::Block(int id) {
    _id = id;
    _placedOn = nullptr;
    _status = true;
    _rate = 1;
    _output_per_second = 5;
}

void Block::simulate() {
    // launch drive function in a thread
    threads.emplace_back(std::thread(&Block::mine, this));
}

void Block::mine() {
    usleep(1000000);

    while (true) {
        usleep(1000000);

        std::cout << "block id: " << this->getID()
                  << std::endl;
        std::cout << "tile id: " << this->_placedOn->getId()
                  << std::endl;
        double cap = this->_placedOn->getCapacity();
        double out = this->getOutput();
        double stored = this->getStored();
        std::cout << "cap: " << this->_placedOn->getCapacity() << "\tout: " << this->getOutput() << "\tstored: " << this->getStored() << std::endl;

        std::cout << "cap: " << this->_placedOn->getCapacity() << "\tout: " << this->getOutput() << "\tstored: " << this->getStored() << std::endl;

        break;

        // if (this->_placedOn->getCapacity() > 0) {
        //     this->addStorage(out, stored);
        //     this->_placedOn->removeCapacity(out, cap);
        //     std::cout << "Mining... " << std::endl;
        // } else {
        //     break;
        // }
    }
}
