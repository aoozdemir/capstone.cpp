#include "block.h"
#include <unistd.h>
#include <iostream>
#include <random>
#include <sstream>
#include "tile.h"

class PrintThread : public std::ostringstream {
   public:
    PrintThread() = default;

    ~PrintThread() {
        std::lock_guard<std::mutex> guard(_mutexPrint);
        std::cout << this->str();
    }

   private:
    static std::mutex _mutexPrint;
};

std::mutex PrintThread::_mutexPrint{};

Block::Block(int id) {
    _id = id;
    _placedOn = nullptr;
    _status = true;
    _rate = 1;
    _output_per_second = rand() % 100 + 5;
}

void Block::mine() {
    usleep(1000000);
    PrintThread{} << "Miner thread id = " << std::this_thread::get_id() << std::endl;

    while (true) {
        usleep(rand() % 10000000 + 5000);
        double cap = this->_placedOn->getCapacity();
        double out = this->getOutput();
        double stored = this->getStored();
        PrintThread{} << "Mining... block id: " << this->getID() << " | tile id: " << this->_placedOn->getId() << "\t\tcap: " << this->_placedOn->getCapacity() << "\t\tout: " << this->getOutput() << "\t\tstored: " << this->getStored() << std::endl;

        this->addStorage(out, stored);
        this->_placedOn->removeCapacity(out, cap);

        if (this->getOutput() > this->_placedOn->getCapacity()) {
            this->addStorage(cap, stored);
            this->_placedOn->removeCapacity(cap, cap);

            PrintThread{} << "\n==================================" << std::endl;
            PrintThread{} << "block id: " << this->getID() << " | tile id: " << this->_placedOn->getId() << " is dried." << std::endl;
            PrintThread{} << "==================================\n"
                          << std::endl;

            break;
        }
    }
}
